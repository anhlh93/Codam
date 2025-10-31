/* ************************************************************************** */
/*                                  TEST MOCKS                               */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Create a mock command structure for testing
 * @param cmd_name Command name (e.g., "ls", "echo")
 * @param args Array of arguments (NULL-terminated)
 * @return Pointer to mock command structure
 */
t_cmds *create_mock_cmd(char *cmd_name, char **args)
{
    t_cmds *cmd = malloc(sizeof(t_cmds));
    int arg_count = 0;

    // Count arguments
    while (args && args[arg_count])
        arg_count++;

    // Allocate and copy arguments
    cmd->str = malloc(sizeof(char *) * (arg_count + 2));
    cmd->str[0] = ft_strdup(cmd_name);

    for (int i = 0; i < arg_count; i++)
        cmd->str[i + 1] = ft_strdup(args[i]);
    cmd->str[arg_count + 1] = NULL;

    // Initialize other fields
    cmd->next = NULL;
    cmd->pid = 0;
    cmd->n = 1;
    cmd->pipefd[0] = -1;
    cmd->pipefd[1] = -1;

    return (cmd);
}

/**
 * @brief Create mock shell structure for testing
 * @return Pointer to mock shell structure
 */
t_shell *create_mock_shell(void)
{
    t_shell *shell = malloc(sizeof(t_shell));
    extern char **environ;

    // Copy environment variables
    int env_count = 0;
    while (environ[env_count])
        env_count++;

    shell->env = malloc(sizeof(char *) * (env_count + 1));
    for (int i = 0; i < env_count; i++)
        shell->env[i] = ft_strdup(environ[i]);
    shell->env[env_count] = NULL;

    shell->cmds = NULL;
    shell->stop = false;

    return (shell);
}

/**
 * @brief Free mock command structure
 */
void free_mock_cmd(t_cmds *cmd)
{
    if (!cmd)
        return;

    for (int i = 0; cmd->str && cmd->str[i]; i++)
        free(cmd->str[i]);
    free(cmd->str);
    free(cmd);
}

/**
 * @brief Free mock shell structure
 */
void free_mock_shell(t_shell *shell)
{
    if (!shell)
        return;

    for (int i = 0; shell->env && shell->env[i]; i++)
        free(shell->env[i]);
    free(shell->env);
    free(shell);
}

/* ************************************************************************** */
/*                                TEST CASES                                 */
/* ************************************************************************** */

/**
 * @brief Test built-in command detection
 */
void test_is_builtin(void)
{
    printf("=== Testing is_builtin() ===\n");

    // Test built-in commands
    char *builtin_args[] = {NULL};
    t_cmds *cmd;

    char *builtins[] = {"pwd", "echo", "cd", "export", "unset", "env", "exit"};
    int builtin_count = sizeof(builtins) / sizeof(builtins[0]);

    for (int i = 0; i < builtin_count; i++)
    {
        cmd = create_mock_cmd(builtins[i], builtin_args);
        printf("%-10s: %s\n", builtins[i], is_builtin(cmd) ? "✓ BUILTIN" : "✗ NOT BUILTIN");
        free_mock_cmd(cmd);
    }

    // Test non-built-in commands
    char *externals[] = {"ls", "cat", "grep", "vim", "gcc"};
    int external_count = sizeof(externals) / sizeof(externals[0]);

    for (int i = 0; i < external_count; i++)
    {
        cmd = create_mock_cmd(externals[i], builtin_args);
        printf("%-10s: %s\n", externals[i], is_builtin(cmd) ? "✗ BUILTIN" : "✓ NOT BUILTIN");
        free_mock_cmd(cmd);
    }
    printf("\n");
}

/**
 * @brief Test execute_currdir function
 */
void test_execute_currdir(void)
{
    printf("=== Testing execute_currdir() ===\n");

    t_shell *shell = create_mock_shell();
    char *args[] = {NULL};

    // Test cases
    struct {
        char *cmd;
        char *description;
    } test_cases[] = {
        {"ls", "Command without slash (should return false)"},
        {"./test_program", "Relative path (should try to execute)"},
        {"/bin/ls", "Absolute path (should try to execute)"},
        {"../script.sh", "Parent directory path"},
        {"", "Empty command (should exit 127)"}
    };

    int case_count = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < case_count; i++)
    {
        printf("Testing: %s - %s\n",
               test_cases[i].cmd, test_cases[i].description);

        t_cmds *cmd = create_mock_cmd(test_cases[i].cmd, args);

        // Note: execute_currdir may exit(), so test carefully
        if (strcmp(test_cases[i].cmd, "") != 0 &&
            ft_strchr(test_cases[i].cmd, '/') != NULL)
        {
            printf("  → Would check access() and potentially execve()\n");
        }
        else
        {
            bool result = execute_currdir(cmd, shell);
            printf("  → Returned: %s\n", result ? "true" : "false");
        }

        free_mock_cmd(cmd);
    }

    free_mock_shell(shell);
    printf("\n");
}

/**
 * @brief Test single command optimization
 */
void test_single_cmd(void)
{
    printf("=== Testing single_cmd() ===\n");

    t_shell *shell = create_mock_shell();

    // Test built-in single command
    char *echo_args[] = {"hello", "world", NULL};
    t_cmds *echo_cmd = create_mock_cmd("echo", echo_args);
    shell->cmds = echo_cmd;

    printf("Testing single echo command:\n");
    bool result = single_cmd(shell);
    printf("  → single_cmd() returned: %s\n", result ? "true" : "false");

    // Test non-built-in single command
    char *ls_args[] = {"-la", NULL};
    t_cmds *ls_cmd = create_mock_cmd("ls", ls_args);
    shell->cmds = ls_cmd;

    printf("Testing single ls command:\n");
    result = single_cmd(shell);
    printf("  → single_cmd() returned: %s\n", result ? "true" : "false");

    free_mock_cmd(echo_cmd);
    free_mock_cmd(ls_cmd);
    free_mock_shell(shell);
    printf("\n");
}

/**
 * @brief Test pipeline creation
 */
void test_pipeline_creation(void)
{
    printf("=== Testing Pipeline Creation ===\n");

    t_shell *shell = create_mock_shell();

    // Create a pipeline: ls | grep .c | wc -l
    char *ls_args[] = {NULL};
    char *grep_args[] = {".c", NULL};
    char *wc_args[] = {"-l", NULL};

    t_cmds *cmd1 = create_mock_cmd("ls", ls_args);
    t_cmds *cmd2 = create_mock_cmd("grep", grep_args);
    t_cmds *cmd3 = create_mock_cmd("wc", wc_args);

    // Link commands
    cmd1->next = cmd2;
    cmd2->next = cmd3;
    cmd1->n = 1;
    cmd2->n = 2;
    cmd3->n = 3;

    shell->cmds = cmd1;

    printf("Created pipeline: ls | grep .c | wc -l\n");
    printf("Command 1: %s (n=%d)\n", cmd1->str[0], cmd1->n);
    printf("Command 2: %s %s (n=%d)\n", cmd2->str[0], cmd2->str[1], cmd2->n);
    printf("Command 3: %s %s (n=%d)\n", cmd3->str[0], cmd3->str[1], cmd3->n);

    // Test if it would use single_cmd optimization
    bool is_single = single_cmd(shell);
    printf("Would use single_cmd optimization: %s\n", is_single ? "Yes" : "No");

    free_mock_cmd(cmd1);
    free_mock_cmd(cmd2);
    free_mock_cmd(cmd3);
    free_mock_shell(shell);
    printf("\n");
}

/**
 * @brief Main test function
 */
int main(void)
{
    printf("🧪 EXECUTOR FUNCTION TESTING 🧪\n");
    printf("=====================================\n\n");

    test_is_builtin();
    test_execute_currdir();
    test_single_cmd();
    test_pipeline_creation();

    printf("=====================================\n");
    printf("✅ All tests completed!\n");
    printf("Note: Some functions may exit() - test those carefully\n");

    return (0);
}
