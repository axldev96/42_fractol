# interpolate

Esta función realiza una interpolación lineal para escalar un valor entre dos números y mantener la proporción.

## Parámetros

* `scale`: Un puntero a una estructura `t_scale` que contiene los siguientes campos:
    * `original_min`: El valor mínimo del rango original.
    * `original_max`: El valor máximo del rango original.
    * `target_min`: El valor mínimo del rango de destino.
    * `target_max`: El valor máximo del rango de destino.
    * `value_to_scale`: El valor que se desea escalar.

## Valor de retorno

La función devuelve el valor escalado en el rango de destino.

## Ejemplo de uso

```c
t_scale scale;
scale.original_min = 0;
scale.original_max = 255;
scale.target_min = 100;
scale.target_max = 200;
scale.value_to_scale = 127;

double scaled_value = interpolate(&scale);

printf("El valor escalado es: %f\n", scaled_value);
