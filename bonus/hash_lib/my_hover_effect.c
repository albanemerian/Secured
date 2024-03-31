/*
** EPITECH PROJECT, 2023
** my_custom_rectangle
** File description:
** Customize a rectangle
*/

#include <SFML/Window.h>
#include <SFML/Graphics.h>

int my_hover_effect(sfRenderWindow *window, sfRectangleShape *rect)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfFloatRect area = sfRectangleShape_getGlobalBounds(rect);

    if (sfFloatRect_contains(&area, mouse.x, mouse.y))
        return (1);
    return (0);
}
