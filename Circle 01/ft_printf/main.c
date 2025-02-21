#include <stdio.h>
#include "ft_printf.h"

int main(void) {
    //// testing %s NULL
    // printf("NULL %s NULL ", NULL);
    // ft_printf("NULL %s NULL ", NULL);
    // printf("%s\n","New test");

    //// testing %p 0
    // printf(" %p %p ", 0, 0);
    // ft_printf(" %p %p ", 0, 0);
    // printf("%s\n","New test");
    // printf("%d %s\n",printf(" %p %p ", 0, 0),"test1");
    // printf("%d %s\n",ft_printf(" %p %p ", 0, 0),"test2");
    // printf("%s\n","New test");

    printf("PRINTF RESULT\n");
    //// testing %p, %s, %i

    // printf("abc %p abc %s abc %i", NULL, NULL, 45);
    // printf("\n");
    // ft_printf("abc %p abc %s abc %i", NULL, NULL, 45);
    // ft_printf("\n");
    // printf("\n%i\n", printf("abc %p abc %s abc %i", NULL, NULL, 45));
    // printf("\n");
    // ft_printf("\n%i\n", ft_printf("abc %p abc %s abc %i", NULL, NULL, 45));
    // printf("\n");

    //// testing %% and \n at the end
    // printf("\n%i\n", printf("%%\n"));
    // printf("\n");

    // //testing %u -1
    // printf("\n%i\n", printf("%u", -1));
    // printf("\n");
    // ft_printf("\n%i\n", ft_printf("%u", -1));
    // printf("\n");

    // //testing %p -1
    // printf("\n%i\n", printf("%p", -1));
    // printf("\n");
    // printf("\n%i\n", ft_printf("%p", -1));
    // printf("\n");

    //// testing direct argument -1, 0, NULL
    // printf("%i",printf(-1));
    // printf("\n");
    // ft_printf("%i",printf(-1));
    // ft_printf("\n");

    //// testing long string more than 2024 character
    // printf("%i",printf("%s","H28XwfHPmbZEFNBiwWJWGkSELUzg7DffZtt1W7dIAm7sFCnLGz78Ft8mSSU1sxmb0TP1U2ZFwP9MMXyo4Ze6xASJSH29JYjfmyzCGsLSZ9vT8MBLrOtJeYOqMPs3ZQTOvF4A76YXKNNHxkAmzEXzfgJpHvEhCH22ItSsxchDOeOO7THAXnC5Kou0azDyUN6Cb34wLOjDB7k7BDun1FSNHj3eZ6YEPiqy5NH4Zbj79Flb7wR1WFGdB5C4iC5aH1XZdiPHhLbTks3ExpJS0cRFpy7t3zb2ZF5slzwunUhCf9cL0LEKdmMT4j8eLODvPzhEaO5CDKTrur25fYDahituJ6b5HLtxO0eqwfbbqwzwMf2KRyUY5xcUCJK1VXwFFXKOIFejeR3EJtNWJu4uE1ZwNj7M2gebCO5RAAmmwVrKndhbtCEFYzPObrHWpnUoJjHFNyMK6KFUQSrofFem8kKmmehApeu7IuSiFFYaK9JHutdNkbtvgqArgxfC0nQgJkcMJYQ144UTKbe9Z40Vg65egVVTVuAZEu0cV0ULbp3MoJKxlFgt6ZLjL7qKh5iv40006dTYhhyDQDlovM7ecDdNXNQlFbFWhnCgr42odUqkO6ez6GDxgy6vOVWBPcQTgEdePxicyKoF8t0EBtCumso66P4lRsMWV8VUAXgl23xc1SbRkEc03PrDEmHcQ6uvdw7vXoUA0ufqmAkjnyrXLndOZJCkYAnRYmFukBBSCnFIfcSgQV9aeV2Z31Vyn1M6ahtBTVpu6vcpUwYVJvxQVKXNrZ1eViVBnIbsd4O4fa0BrtDBMjCjUTgYwfrB7RmNxoVWk8V6mcimWocK6rmfm6OmDmrcQf06fhg0gQi9DLGdgsgfVWpFuZ7mQcJhz7zVfQ1EXUlocw8sx3QHr3V2qbysIySCTCzYbF5oofWzahxk8Ywo6g1aXkqbLXZfZVkvEHERQJ7mCT7K3qmpl5yK5x7U3uMXMSnFylMPk93xT1j7LPoiY547fiFFYAfmwgyaUEJv"));
    // printf("\n");
    // ft_printf("%i",ft_printf("%s","H28XwfHPmbZEFNBiwWJWGkSELUzg7DffZtt1W7dIAm7sFCnLGz78Ft8mSSU1sxmb0TP1U2ZFwP9MMXyo4Ze6xASJSH29JYjfmyzCGsLSZ9vT8MBLrOtJeYOqMPs3ZQTOvF4A76YXKNNHxkAmzEXzfgJpHvEhCH22ItSsxchDOeOO7THAXnC5Kou0azDyUN6Cb34wLOjDB7k7BDun1FSNHj3eZ6YEPiqy5NH4Zbj79Flb7wR1WFGdB5C4iC5aH1XZdiPHhLbTks3ExpJS0cRFpy7t3zb2ZF5slzwunUhCf9cL0LEKdmMT4j8eLODvPzhEaO5CDKTrur25fYDahituJ6b5HLtxO0eqwfbbqwzwMf2KRyUY5xcUCJK1VXwFFXKOIFejeR3EJtNWJu4uE1ZwNj7M2gebCO5RAAmmwVrKndhbtCEFYzPObrHWpnUoJjHFNyMK6KFUQSrofFem8kKmmehApeu7IuSiFFYaK9JHutdNkbtvgqArgxfC0nQgJkcMJYQ144UTKbe9Z40Vg65egVVTVuAZEu0cV0ULbp3MoJKxlFgt6ZLjL7qKh5iv40006dTYhhyDQDlovM7ecDdNXNQlFbFWhnCgr42odUqkO6ez6GDxgy6vOVWBPcQTgEdePxicyKoF8t0EBtCumso66P4lRsMWV8VUAXgl23xc1SbRkEc03PrDEmHcQ6uvdw7vXoUA0ufqmAkjnyrXLndOZJCkYAnRYmFukBBSCnFIfcSgQV9aeV2Z31Vyn1M6ahtBTVpu6vcpUwYVJvxQVKXNrZ1eViVBnIbsd4O4fa0BrtDBMjCjUTgYwfrB7RmNxoVWk8V6mcimWocK6rmfm6OmDmrcQf06fhg0gQi9DLGdgsgfVWpFuZ7mQcJhz7zVfQ1EXUlocw8sx3QHr3V2qbysIySCTCzYbF5oofWzahxk8Ywo6g1aXkqbLXZfZVkvEHERQJ7mCT7K3qmpl5yK5x7U3uMXMSnFylMPk93xT1j7LPoiY547fiFFYAfmwgyaUEJv"));
    // ft_printf("\n");
    
    ft_printf("FT_PRINTF RESULT\n");


    return 0;
    }

