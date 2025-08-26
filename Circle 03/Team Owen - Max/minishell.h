# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <signal.h>
# include <limits.h>

# include <readline/readline.h>
# include <readline/history.h>

# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>

# ifndef PATH_MAX
#  define PATH_MAX 1024
# endif

# define STDIN 0
# define STDOUT 1
# define STDERR 2

typedef struct s_cmds
{
    char            **str;          // Command and arguments array
    t_lexer         *redir;         // Redirection tokens/nodes
    int             n;              // Command index in pipeline
    pid_t           pid;            // Process ID when executed
    int             pipefd[2];      // Pipe file descriptors [read, write]
    char            *heredoc;       // Here-document content buffer
    struct s_cmds   *next;          // Next command in pipeline (linked list)
}					t_cmds;

typedef struct s_shell
{
	char	**env;
	char	**sorted_env;
	bool	stop;
	t_cmds	*cmds;
}			t_shell;

int	g_return_value;

//Executor
void	execute(t_shell *shell);
bool	single_cmd(t_shell *shell);
int		execute_builtin(t_cmds *cmd, t_shell *shell);
void	ft_execve(t_cmds *cmd, t_shell *shell, char **path);
void	ft_waitpid(t_shell *shell);
bool	is_builtin(t_cmds *cmd);
int		ft_dup(int fd);
void	ft_dup2(int fd1, int fd2);
pid_t	ft_fork(void);
void	ft_pipe(int fd[2]);
