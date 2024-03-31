/*
** EPITECH PROJECT, 2024
** B-CPE-110-NAN-1-1-secured-albane.merian
** File description:
** main
*/

#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "include/hashtable.h"
#include "include/my.h"

static void empty_scene(sfRectangleShape **button, sfText **text)
{
    sfFont *font = sfFont_createFromFile("./assets/old.ttf");

    sfRectangleShape_setSize(*button, (sfVector2f) {690, 300});
    sfRectangleShape_setPosition(*button, (sfVector2f) {630, 405});
    sfRectangleShape_setFillColor(*button, sfTransparent);
    sfRectangleShape_setOutlineColor(*button, sfBlack);
    sfRectangleShape_setOutlineThickness(*button, 3);
    sfText_setFont(*text, font);
    sfText_setCharacterSize(*text, 75);
    sfText_setColor(*text, sfWhite);
    sfText_setPosition(*text, (sfVector2f) {635, 510});
    sfText_setString(*text, "N e w  H a s h t a b l e");
}

static sfRectangleShape **size_button(sfRectangleShape **buttons)
{
    for (int i = 0; i < 9; i++) {
        buttons[i] = sfRectangleShape_create();
        sfRectangleShape_setSize(buttons[i], (sfVector2f) {200, 270});
        sfRectangleShape_setFillColor(buttons[i], sfWhite);
        sfRectangleShape_setOutlineColor(buttons[i], sfBlack);
        sfRectangleShape_setOutlineThickness(buttons[i], 2);
    }
    return (buttons);
}

static sfRectangleShape *delete_button(void)
{
    sfRectangleShape *button = sfRectangleShape_create();

    sfRectangleShape_setSize(button, (sfVector2f) {445, 45});
    sfRectangleShape_setFillColor(button, sfTransparent);
    sfRectangleShape_setPosition(button, (sfVector2f) {1028, 770});
    return (button);
}

static sfRectangleShape *delkey_button(void)
{
    sfRectangleShape *button = sfRectangleShape_create();

    sfRectangleShape_setSize(button, (sfVector2f) {445, 45});
    sfRectangleShape_setFillColor(button, sfTransparent);
    sfRectangleShape_setPosition(button, (sfVector2f) {1025, 670});
    return (button);
}

static sfRectangleShape *dump_button(void)
{
    sfRectangleShape *button = sfRectangleShape_create();

    sfRectangleShape_setSize(button, (sfVector2f) {245, 45});
    sfRectangleShape_setFillColor(button, sfTransparent);
    sfRectangleShape_setPosition(button, (sfVector2f) {1130, 470});
    return (button);
}

static sfRectangleShape *insert_button(void)
{
    sfRectangleShape *button = sfRectangleShape_create();

    sfRectangleShape_setSize(button, (sfVector2f) {280, 40});
    sfRectangleShape_setFillColor(button, sfTransparent);
    sfRectangleShape_setPosition(button, (sfVector2f) {1110, 370});
    return (button);
}

static sfRectangleShape *search_button(void)
{
    sfRectangleShape *button = sfRectangleShape_create();

    sfRectangleShape_setSize(button, (sfVector2f) {292, 40});
    sfRectangleShape_setFillColor(button, sfTransparent);
    sfRectangleShape_setPosition(button, (sfVector2f) {1110, 570});
    return (button);
}

static sfText *search_text(void)
{
    sfFont *font = sfFont_createFromFile("./assets/old.ttf");
    sfText *button = sfText_create();

    sfText_setFont(button, font);
    sfText_setCharacterSize(button, 55);
    sfText_setColor(button, sfBlack);
    sfText_setPosition(button, (sfVector2f) {1110, 550});
    sfText_setString(button, "- S e a r c h -");
    return (button);
}

static sfText *insert_text(void)
{
    sfFont *font = sfFont_createFromFile("./assets/old.ttf");
    sfText *button = sfText_create();

    sfText_setFont(button, font);
    sfText_setCharacterSize(button, 55);
    sfText_setColor(button, sfBlack);
    sfText_setPosition(button, (sfVector2f) {1110, 350});
    sfText_setString(button, "- I n s e r t -");
    return (button);
}

static sfText *delkey_text(void)
{
    sfFont *font = sfFont_createFromFile("./assets/old.ttf");
    sfText *button = sfText_create();

    sfText_setFont(button, font);
    sfText_setCharacterSize(button, 55);
    sfText_setColor(button, sfWhite);
    sfText_setPosition(button, (sfVector2f) {1025, 650});
    sfText_setString(button, "- D e l e t e   K e y -");
    return (button);
}

static sfText *destroy_text(void)
{
    sfFont *font = sfFont_createFromFile("./assets/old.ttf");
    sfText *button = sfText_create();

    sfText_setFont(button, font);
    sfText_setCharacterSize(button, 55);
    sfText_setColor(button, sfRed);
    sfText_setPosition(button, (sfVector2f) {1020, 750});
    sfText_setString(button, "- D e s t r o y   H t -");
    return (button);
}

static sfText *dump_text(void)
{
    sfFont *font = sfFont_createFromFile("./assets/old.ttf");
    sfText *button = sfText_create();

    sfText_setFont(button, font);
    sfText_setCharacterSize(button, 55);
    sfText_setColor(button, sfBlack);
    sfText_setPosition(button, (sfVector2f) {1130, 450});
    sfText_setString(button, "- D u m p -");
    return (button);
}

static sfText *size_hashtable(sfText *text, hashtable_t *ht)
{
    sfFont *font = sfFont_createFromFile("./assets/old.ttf");
    sfColor cool = {96, 43, 40, 255};
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 50);
    sfText_setColor(text, cool);
    sfText_setPosition(text, (sfVector2f) {850, 200});
    sfText_setString(text, my_itoa(ht->size));
    return (text);
}

static sfText **size_text(sfText **buttons)
{
    sfFont *font = sfFont_createFromFile("./assets/old.ttf");

    for (int i = 0; i < 9; i++) {
        buttons[i] = sfText_create();
        sfText_setFont(buttons[i], font);
        sfText_setCharacterSize(buttons[i], 45);
        sfText_setColor(buttons[i], sfBlack);
        sfText_setString(buttons[i], my_itoa(i + 1));
    }
    return (buttons);
}

static sfText **book_text(sfText **buttons)
{
    sfFont *font = sfFont_createFromFile("./assets/old.ttf");
    sfColor cool =  {210, 184, 100, 255};

    for (int i = 0; i < 9; i++) {
        buttons[i] = sfText_create();
        sfText_setFont(buttons[i], font);
        sfText_setCharacterSize(buttons[i], 60);
        sfText_setColor(buttons[i], cool);
        sfText_setString(buttons[i], my_itoa(i + 1));
    }
    return (buttons);
}

static sfRectangleShape **several_keys(void)
{
    sfRectangleShape **buttons = malloc(sizeof(sfRectangleShape *) * 20);

    for (int i = 0; i < 20; i++) {
        buttons[i] = sfRectangleShape_create();
        sfRectangleShape_setSize(buttons[i], (sfVector2f) {400, 100});
        sfRectangleShape_setFillColor(buttons[i], sfWhite);
        sfRectangleShape_setOutlineColor(buttons[i], sfBlack);
        sfRectangleShape_setOutlineThickness(buttons[i], 2);
    }
    return (buttons);
}

static sfText **name_keys()
{
    sfText **button = malloc(sizeof(sfText *) * 20);
    sfFont *font = sfFont_createFromFile("./assets/old.ttf");

    button[0] = sfText_create();
    sfText_setFont(button[0], font);
    sfText_setCharacterSize(button[0], 35);
    sfText_setColor(button[0], sfBlack);
    sfText_setPosition(button[0], (sfVector2f) {120, 285});
    sfText_setString(button[0], "Bring Me The Horizon");
    button[1] = sfText_create();
    sfText_setFont(button[1], font);
    sfText_setCharacterSize(button[1], 35);
    sfText_setColor(button[1], sfBlack);
    sfText_setPosition(button[1], (sfVector2f) {180, 440});
    sfText_setString(button[1], "Sleep Token");
    button[2] = sfText_create();
    sfText_setFont(button[2], font);
    sfText_setCharacterSize(button[2], 35);
    sfText_setColor(button[2], sfBlack);
    sfText_setPosition(button[2], (sfVector2f) {130, 590});
    sfText_setString(button[2], "Falling in Reverse");
    button[3] = sfText_create();
    sfText_setFont(button[3], font);
    sfText_setCharacterSize(button[3], 35);
    sfText_setColor(button[3], sfBlack);
    sfText_setPosition(button[3], (sfVector2f) {110, 740});
    sfText_setString(button[3], "My Chemical Romance");
    button[4] = sfText_create();
    sfText_setFont(button[4], font);
    sfText_setCharacterSize(button[4], 35);
    sfText_setColor(button[4], sfBlack);
    sfText_setPosition(button[4], (sfVector2f) {130, 890});
    sfText_setString(button[4], "Panic! at the Disco");
    button[5] = sfText_create();
    sfText_setFont(button[5], font);
    sfText_setCharacterSize(button[5], 35);
    sfText_setColor(button[5], sfBlack);
    sfText_setPosition(button[5], (sfVector2f) {580, 285});
    sfText_setString(button[5], "Machine Gun Kelly");
    button[6] = sfText_create();
    sfText_setFont(button[6], font);
    sfText_setCharacterSize(button[6], 35);
    sfText_setColor(button[6], sfBlack);
    sfText_setPosition(button[6], (sfVector2f) {630, 440});
    sfText_setString(button[6], "Tokio Hotel");
    button[7] = sfText_create();
    sfText_setFont(button[7], font);
    sfText_setCharacterSize(button[7], 35);
    sfText_setColor(button[7], sfBlack);
    sfText_setPosition(button[7], (sfVector2f) {600, 590});
    sfText_setString(button[7], "Johnnie Guilbert");
    button[8] = sfText_create();
    sfText_setFont(button[8], font);
    sfText_setCharacterSize(button[8], 35);
    sfText_setColor(button[8], sfBlack);
    sfText_setPosition(button[8], (sfVector2f) {675, 740});
    sfText_setString(button[8], "Mayhem");
    button[9] = sfText_create();
    sfText_setFont(button[9], font);
    sfText_setCharacterSize(button[9], 35);
    sfText_setColor(button[9], sfBlack);
    sfText_setPosition(button[9], (sfVector2f) {630, 890});
    sfText_setString(button[9], "Fallout Boy");
    button[10] = sfText_create();
    sfText_setFont(button[10], font);
    sfText_setCharacterSize(button[10], 35);
    sfText_setColor(button[10], sfBlack);
    sfText_setPosition(button[10], (sfVector2f) {1050, 285});
    sfText_setString(button[10], "Pierce the Veil");
    button[11] = sfText_create();
    sfText_setFont(button[11], font);
    sfText_setCharacterSize(button[11], 35);
    sfText_setColor(button[11], sfBlack);
    sfText_setPosition(button[11], (sfVector2f) {1100, 440});
    sfText_setString(button[11], "Paramore");
    button[12] = sfText_create();
    sfText_setFont(button[12], font);
    sfText_setCharacterSize(button[12], 35);
    sfText_setColor(button[12], sfBlack);
    sfText_setPosition(button[12], (sfVector2f) {1130, 590});
    sfText_setString(button[12], "Ghost");
    button[13] = sfText_create();
    sfText_setFont(button[13], font);
    sfText_setCharacterSize(button[13], 35);
    sfText_setColor(button[13], sfBlack);
    sfText_setPosition(button[13], (sfVector2f) {1120, 740});
    sfText_setString(button[13], "Nirvana");
    button[14] = sfText_create();
    sfText_setFont(button[14], font);
    sfText_setCharacterSize(button[14], 35);
    sfText_setColor(button[14], sfBlack);
    sfText_setPosition(button[14], (sfVector2f) {1060, 890});
    sfText_setString(button[14], "Marilyn Manson");
    button[15] = sfText_create();
    sfText_setFont(button[15], font);
    sfText_setCharacterSize(button[15], 35);
    sfText_setColor(button[15], sfBlack);
    sfText_setPosition(button[15], (sfVector2f) {1525, 285});
    sfText_setString(button[15], "Jake Webber");
    button[16] = sfText_create();
    sfText_setFont(button[16], font);
    sfText_setCharacterSize(button[16], 35);
    sfText_setColor(button[16], sfBlack);
    sfText_setPosition(button[16], (sfVector2f) {1525, 440});
    sfText_setString(button[16], "Motley Crue");
    button[17] = sfText_create();
    sfText_setFont(button[17], font);
    sfText_setCharacterSize(button[17], 35);
    sfText_setColor(button[17], sfBlack);
    sfText_setPosition(button[17], (sfVector2f) {1550, 590});
    sfText_setString(button[17], "Slipknot");
    button[18] = sfText_create();
    sfText_setFont(button[18], font);
    sfText_setCharacterSize(button[18], 35);
    sfText_setColor(button[18], sfBlack);
    sfText_setPosition(button[18], (sfVector2f) {1520, 740});
    sfText_setString(button[18], "Ice Nine Kills");
    button[19] = sfText_create();
    sfText_setFont(button[19], font);
    sfText_setCharacterSize(button[19], 35);
    sfText_setColor(button[19], sfBlack);
    sfText_setPosition(button[19], (sfVector2f) {1550, 890});
    sfText_setString(button[19], "Scorpions");
    return (button);
}

static sfText **name_val()
{
    sfText **button = malloc(sizeof(sfText *) * 20);
    sfFont *font = sfFont_createFromFile("./assets/old.ttf");

    button[0] = sfText_create();
    sfText_setFont(button[0], font);
    sfText_setCharacterSize(button[0], 35);
    sfText_setColor(button[0], sfBlack);
    sfText_setPosition(button[0], (sfVector2f) {205, 285});
    sfText_setString(button[0], "Alkaline");
    button[1] = sfText_create();
    sfText_setFont(button[1], font);
    sfText_setCharacterSize(button[1], 35);
    sfText_setColor(button[1], sfBlack);
    sfText_setPosition(button[1], (sfVector2f) {105, 440});
    sfText_setString(button[1], "Can You Feel My Heart");
    button[2] = sfText_create();
    sfText_setFont(button[2], font);
    sfText_setCharacterSize(button[2], 35);
    sfText_setColor(button[2], sfBlack);
    sfText_setPosition(button[2], (sfVector2f) {150, 590});
    sfText_setString(button[2], "Drug in Me Is You");
    button[3] = sfText_create();
    sfText_setFont(button[3], font);
    sfText_setCharacterSize(button[3], 35);
    sfText_setColor(button[3], sfBlack);
    sfText_setPosition(button[3], (sfVector2f) {170, 740});
    sfText_setString(button[3], "Kakou Kakou");
    button[4] = sfText_create();
    sfText_setFont(button[4], font);
    sfText_setCharacterSize(button[4], 35);
    sfText_setColor(button[4], sfBlack);
    sfText_setPosition(button[4], (sfVector2f) {180, 890});
    sfText_setString(button[4], "Rondoudou");
    button[5] = sfText_create();
    sfText_setFont(button[5], font);
    sfText_setCharacterSize(button[5], 35);
    sfText_setColor(button[5], sfBlack);
    sfText_setPosition(button[5], (sfVector2f) {625, 285});
    sfText_setString(button[5], "Black Parade");
    button[6] = sfText_create();
    sfText_setFont(button[6], font);
    sfText_setCharacterSize(button[6], 35);
    sfText_setColor(button[6], sfBlack);
    sfText_setPosition(button[6], (sfVector2f) {590, 440});
    sfText_setString(button[6], "Durch den Monsun");
    button[7] = sfText_create();
    sfText_setFont(button[7], font);
    sfText_setCharacterSize(button[7], 35);
    sfText_setColor(button[7], sfBlack);
    sfText_setPosition(button[7], (sfVector2f) {690, 590});
    sfText_setString(button[7], "KMS");
    button[8] = sfText_create();
    sfText_setFont(button[8], font);
    sfText_setCharacterSize(button[8], 35);
    sfText_setColor(button[8], sfBlack);
    sfText_setPosition(button[8], (sfVector2f) {537, 740});
    sfText_setString(button[8], "I Write Sins No Tragedies");
    button[9] = sfText_create();
    sfText_setFont(button[9], font);
    sfText_setCharacterSize(button[9], 35);
    sfText_setColor(button[9], sfBlack);
    sfText_setPosition(button[9], (sfVector2f) {570, 890});
    sfText_setString(button[9], "Broken at the Seams");
    button[10] = sfText_create();
    sfText_setFont(button[10], font);
    sfText_setCharacterSize(button[10], 35);
    sfText_setColor(button[10], sfBlack);
    sfText_setPosition(button[10], (sfVector2f) {1070, 285});
    sfText_setString(button[10], "Dance, Dance!");
    button[11] = sfText_create();
    sfText_setFont(button[11], font);
    sfText_setCharacterSize(button[11], 35);
    sfText_setColor(button[11], sfBlack);
    sfText_setPosition(button[11], (sfVector2f) {1050, 440});
    sfText_setString(button[11], "Misery Buisness");
    button[12] = sfText_create();
    sfText_setFont(button[12], font);
    sfText_setCharacterSize(button[12], 35);
    sfText_setColor(button[12], sfBlack);
    sfText_setPosition(button[12], (sfVector2f) {1080, 590});
    sfText_setString(button[12], "God Save Me");
    button[13] = sfText_create();
    sfText_setFont(button[13], font);
    sfText_setCharacterSize(button[13], 35);
    sfText_setColor(button[13], sfBlack);
    sfText_setPosition(button[13], (sfVector2f) {1120, 740});
    sfText_setString(button[13], "Crybaby");
    button[14] = sfText_create();
    sfText_setFont(button[14], font);
    sfText_setCharacterSize(button[14], 35);
    sfText_setColor(button[14], sfBlack);
    sfText_setPosition(button[14], (sfVector2f) {1070, 890});
    sfText_setString(button[14], "Save that Shit");
    button[15] = sfText_create();
    sfText_setFont(button[15], font);
    sfText_setCharacterSize(button[15], 35);
    sfText_setColor(button[15], sfBlack);
    sfText_setPosition(button[15], (sfVector2f) {1560, 285});
    sfText_setString(button[15], "Crunchy");
    button[16] = sfText_create();
    sfText_setFont(button[16], font);
    sfText_setCharacterSize(button[16], 35);
    sfText_setColor(button[16], sfBlack);
    sfText_setPosition(button[16], (sfVector2f) {1525, 440});
    sfText_setString(button[16], "Croustillant");
    button[17] = sfText_create();
    sfText_setFont(button[17], font);
    sfText_setCharacterSize(button[17], 35);
    sfText_setColor(button[17], sfBlack);
    sfText_setPosition(button[17], (sfVector2f) {1580, 590});
    sfText_setString(button[17], "Niglo");
    button[18] = sfText_create();
    sfText_setFont(button[18], font);
    sfText_setCharacterSize(button[18], 35);
    sfText_setColor(button[18], sfBlack);
    sfText_setPosition(button[18], (sfVector2f) {1560, 740});
    sfText_setString(button[18], "Pumpkin!");
    button[19] = sfText_create();
    sfText_setFont(button[19], font);
    sfText_setCharacterSize(button[19], 35);
    sfText_setColor(button[19], sfBlack);
    sfText_setPosition(button[19], (sfVector2f) {1500, 890});
    sfText_setString(button[19], "End of the Show");
    return (button);
}

static char *key_key(scenes_t *scenes, sfRenderWindow *win, sfRectangleShape **buttons, char **elem)
{
    if (my_hover_effect(win, buttons[0]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Bring Me The Horizon");
        scenes->insert_key = false;
        usleep(300000);
        scenes->insert_val = true;
    }
    if (my_hover_effect(win, buttons[1]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Sleep Token");
        scenes->insert_key = false;
        usleep(300000);
        scenes->insert_val = true;
    }
    if (my_hover_effect(win, buttons[2]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Falling in Reverse");
        scenes->insert_key = false;
        usleep(300000);
        scenes->insert_val = true;
    }
    if (my_hover_effect(win, buttons[3]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("My Chemical Romance");
        scenes->insert_key = false;
        usleep(300000);
        scenes->insert_val = true;
    }
    if (my_hover_effect(win, buttons[4]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Panic! at the Disco");
        scenes->insert_key = false;
        usleep(300000);
        scenes->insert_val = true;
    }
    if (my_hover_effect(win, buttons[5]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Machine Gun Kelly");
        scenes->insert_key = false;
        usleep(300000);
        scenes->insert_val = true;
    }
    if (my_hover_effect(win, buttons[6]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Tokio Hotel");
        scenes->insert_key = false;
        usleep(300000);
        scenes->insert_val = true;
    }
    if (my_hover_effect(win, buttons[7]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Johnnie Guilbert");
        scenes->insert_key = false;
        usleep(300000);
        scenes->insert_val = true;
    }
    if (my_hover_effect(win, buttons[8]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Mayhem");
        scenes->insert_key = false;
        usleep(300000);
        scenes->insert_val = true;
    }
    if (my_hover_effect(win, buttons[9]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Fallout Boy");
        scenes->insert_key = false;
        usleep(300000);
        scenes->insert_val = true;
    }
    if (my_hover_effect(win, buttons[10]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Pierce the Veil");
        scenes->insert_key = false;
        usleep(300000);
        scenes->insert_val = true;
    }
    if (my_hover_effect(win, buttons[11]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Paramore");
        scenes->insert_key = false;
        usleep(300000);
        scenes->insert_val = true;
    }
    if (my_hover_effect(win, buttons[12]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Ghost");
        scenes->insert_key = false;
        usleep(300000);
        scenes->insert_val = true;
    }
    if (my_hover_effect(win, buttons[13]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Nirvana");
        scenes->insert_key = false;
        usleep(300000);
        scenes->insert_val = true;
    }
    if (my_hover_effect(win, buttons[14]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Marilyn Manson");
        scenes->insert_key = false;
        usleep(300000);
        scenes->insert_val = true;
    }
    if (my_hover_effect(win, buttons[15]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Jake Webber");
        scenes->insert_key = false;
        usleep(300000);
        scenes->insert_val = true;
    }
    if (my_hover_effect(win, buttons[16]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Motley Crue");
        scenes->insert_key = false;
        usleep(300000);
        scenes->insert_val = true;
    }
    if (my_hover_effect(win, buttons[17]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Slipknot");
        scenes->insert_key = false;
        usleep(300000);
        scenes->insert_val = true;
    }
    if (my_hover_effect(win, buttons[18]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Ice Nine Kills");
        scenes->insert_key = false;
        usleep(300000);
        scenes->insert_val = true;
    }
    if (my_hover_effect(win, buttons[19]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Scorpions");
        scenes->insert_key = false;
        usleep(300000);
        scenes->insert_val = true;
    }
}

static char *key_delete(scenes_t *scenes, sfRenderWindow *win, sfRectangleShape **buttons, char **elem)
{
    if (my_hover_effect(win, buttons[0]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Bring Me The Horizon");
        scenes->elem -= 1;
        scenes->delkey = false;
        usleep(300000);
        scenes->deletion = true;
    }
    if (my_hover_effect(win, buttons[1]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Sleep Token");
        scenes->elem -= 1;
        scenes->delkey = false;
        usleep(300000);
        scenes->deletion = true;
    }
    if (my_hover_effect(win, buttons[2]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Falling in Reverse");
        scenes->elem -= 1;
        scenes->delkey = false;
        usleep(300000);
        scenes->deletion = true;
    }
    if (my_hover_effect(win, buttons[3]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("My Chemical Romance");
        scenes->elem -= 1;
        scenes->delkey = false;
        usleep(300000);
        scenes->deletion = true;
    }
    if (my_hover_effect(win, buttons[4]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Panic! at the Disco");
        scenes->elem -= 1;
        scenes->delkey = false;
        usleep(300000);
        scenes->deletion = true;
    }
    if (my_hover_effect(win, buttons[5]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Machine Gun Kelly");
        scenes->elem -= 1;
        scenes->delkey = false;
        usleep(300000);
        scenes->deletion = true;
    }
    if (my_hover_effect(win, buttons[6]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Tokio Hotel");
        scenes->elem -= 1;
        scenes->delkey = false;
        usleep(300000);
        scenes->deletion = true;
    }
    if (my_hover_effect(win, buttons[7]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Johnnie Guilbert");
        scenes->elem -= 1;
        scenes->delkey = false;
        usleep(300000);
        scenes->deletion = true;
    }
    if (my_hover_effect(win, buttons[8]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Mayhem");
        scenes->elem -= 1;
        scenes->delkey = false;
        usleep(300000);
        scenes->deletion = true;
    }
    if (my_hover_effect(win, buttons[9]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Fallout Boy");
        scenes->elem -= 1;
        scenes->delkey = false;
        usleep(300000);
        scenes->deletion = true;
    }
    if (my_hover_effect(win, buttons[10]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Pierce the Veil");
        scenes->elem -= 1;
        scenes->delkey = false;
        usleep(300000);
        scenes->deletion = true;
    }
    if (my_hover_effect(win, buttons[11]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Paramore");
        scenes->elem -= 1;
        scenes->delkey = false;
        usleep(300000);
        scenes->deletion = true;
    }
    if (my_hover_effect(win, buttons[12]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Ghost");
        scenes->elem -= 1;
        scenes->delkey = false;
        usleep(300000);
        scenes->deletion = true;
    }
    if (my_hover_effect(win, buttons[13]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Nirvana");
        scenes->elem -= 1;
        scenes->delkey = false;
        usleep(300000);
        scenes->deletion = true;
    }
    if (my_hover_effect(win, buttons[14]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Marilyn Manson");
        scenes->elem -= 1;
        scenes->delkey = false;
        usleep(300000);
        scenes->deletion = true;
    }
    if (my_hover_effect(win, buttons[15]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Jake Webber");
        scenes->elem -= 1;
        scenes->delkey = false;
        usleep(300000);
        scenes->deletion = true;
    }
    if (my_hover_effect(win, buttons[16]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Motley Crue");
        scenes->elem -= 1;
        scenes->delkey = false;
        usleep(300000);
        scenes->deletion = true;
    }
    if (my_hover_effect(win, buttons[17]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Slipknot");
        scenes->elem -= 1;
        scenes->delkey = false;
        usleep(300000);
        scenes->deletion = true;
    }
    if (my_hover_effect(win, buttons[18]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Ice Nine Kills");
        scenes->elem -= 1;
        scenes->delkey = false;
        usleep(300000);
        scenes->deletion = true;
    }
    if (my_hover_effect(win, buttons[19]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Scorpions");
        scenes->elem -= 1;
        scenes->delkey = false;
        usleep(300000);
        scenes->deletion = true;
    }
}

static char *key_search(scenes_t *scenes, sfRenderWindow *win, sfRectangleShape **buttons, char **elem, int *nb_search)
{
    if (my_hover_effect(win, buttons[0]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Bring Me The Horizon");
        *nb_search += 1;
        scenes->search = false;
        usleep(300000);
        scenes->ht = true;
    }
    if (my_hover_effect(win, buttons[1]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Sleep Token");
        *nb_search += 1;
        scenes->search = false;
        usleep(300000);
        scenes->ht = true;
    }
    if (my_hover_effect(win, buttons[2]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Falling in Reverse");
        *nb_search += 1;
        scenes->search = false;
        usleep(300000);
        scenes->ht = true;
    }
    if (my_hover_effect(win, buttons[3]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("My Chemical Romance");
        *nb_search += 1;
        scenes->search = false;
        usleep(300000);
        scenes->ht = true;
    }
    if (my_hover_effect(win, buttons[4]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Panic! at the Disco");
        *nb_search += 1;
        scenes->search = false;
        usleep(300000);
        scenes->ht = true;
    }
    if (my_hover_effect(win, buttons[5]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Machine Gun Kelly");
        *nb_search += 1;
        scenes->search = false;
        usleep(300000);
        scenes->ht = true;
    }
    if (my_hover_effect(win, buttons[6]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Tokio Hotel");
        *nb_search += 1;
        scenes->search = false;
        usleep(300000);
        scenes->ht = true;
    }
    if (my_hover_effect(win, buttons[7]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Johnnie Guilbert");
        *nb_search += 1;
        scenes->search = false;
        usleep(300000);
        scenes->ht = true;
    }
    if (my_hover_effect(win, buttons[8]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Mayhem");
        *nb_search += 1;
        scenes->search = false;
        usleep(300000);
        scenes->ht = true;
    }
    if (my_hover_effect(win, buttons[9]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Fallout Boy");
        *nb_search += 1;
        scenes->search = false;
        usleep(300000);
        scenes->ht = true;
    }
    if (my_hover_effect(win, buttons[10]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Pierce the Veil");
        *nb_search += 1;
        scenes->search = false;
        usleep(300000);
        scenes->ht = true;
    }
    if (my_hover_effect(win, buttons[11]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Paramore");
        *nb_search += 1;
        scenes->search = false;
        usleep(300000);
        scenes->ht = true;
    }
    if (my_hover_effect(win, buttons[12]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Ghost");
        *nb_search += 1;
        scenes->search = false;
        usleep(300000);
        scenes->ht = true;
    }
    if (my_hover_effect(win, buttons[13]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Nirvana");
        *nb_search += 1;
        scenes->search = false;
        usleep(300000);
        scenes->ht = true;
    }
    if (my_hover_effect(win, buttons[14]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Marilyn Manson");
        *nb_search += 1;
        scenes->search = false;
        usleep(300000);
        scenes->ht = true;
    }
    if (my_hover_effect(win, buttons[15]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Jake Webber");
        *nb_search += 1;
        scenes->search = false;
        usleep(300000);
        scenes->ht = true;
    }
    if (my_hover_effect(win, buttons[16]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Motley Crue");
        *nb_search += 1;
        scenes->search = false;
        usleep(300000);
        scenes->ht = true;
    }
    if (my_hover_effect(win, buttons[17]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Slipknot");
        *nb_search += 1;
        scenes->search = false;
        usleep(300000);
        scenes->ht = true;
    }
    if (my_hover_effect(win, buttons[18]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Ice Nine Kills");
        *nb_search += 1;
        scenes->search = false;
        usleep(300000);
        scenes->ht = true;
    }
    if (my_hover_effect(win, buttons[19]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem = my_strdup("Scorpions");
        *nb_search += 1;
        scenes->search = false;
        usleep(300000);
        scenes->ht = true;
    }
}

static void val_val(scenes_t *scenes, sfRenderWindow *win, sfRectangleShape **buttons, char **elem2)
{
    if (my_hover_effect(win, buttons[0]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem2 = my_strdup("Alkaline");
        scenes->insert_val = false;
        usleep(300000);
        scenes->insert = true;
    }
    if (my_hover_effect(win, buttons[1]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem2 = my_strdup("Can You Feel My Heart");
        scenes->insert_val = false;
        usleep(300000);
        scenes->insert = true;
    }
    if (my_hover_effect(win, buttons[2]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        scenes->insert_val = false;
        usleep(300000);
        scenes->insert = true;
        *elem2 = my_strdup("Drug in Me Is You");
    }
    if (my_hover_effect(win, buttons[3]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem2 = my_strdup("Kakou Kakou");
        scenes->insert_val = false;
        usleep(300000);
        scenes->insert = true;
    }
    if (my_hover_effect(win, buttons[4]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem2 = my_strdup("Rondoudou");
        scenes->insert_val = false;
        usleep(300000);
        scenes->insert = true;
    }
    if (my_hover_effect(win, buttons[5]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem2 = my_strdup("Black Parade");
        scenes->insert_val = false;
        usleep(300000);
        scenes->insert = true;
    }
    if (my_hover_effect(win, buttons[6]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem2 = my_strdup("Durch den Monsun");
        scenes->insert_val = false;
        usleep(300000);
        scenes->insert = true;
    }
    if (my_hover_effect(win, buttons[7]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem2 = my_strdup("KMS");
        scenes->insert_val = false;
        usleep(300000);
        scenes->insert = true;
    }
    if (my_hover_effect(win, buttons[8]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem2 = my_strdup("I Write Sins No Tragedies");
        scenes->insert_val = false;
        usleep(300000);
        scenes->insert = true;
    }
    if (my_hover_effect(win, buttons[9]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem2 = my_strdup("Sleeping with your Ghost");
        scenes->insert_val = false;
        usleep(300000);
        scenes->insert = true;
    }
    if (my_hover_effect(win, buttons[10]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem2 = my_strdup("Dance, Dance!");
        scenes->insert_val = false;
        usleep(300000);
        scenes->insert = true;
    }
    if (my_hover_effect(win, buttons[11]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem2 = my_strdup("Misery Buisness");
        scenes->insert_val = false;
        usleep(300000);
        scenes->insert = true;
    }
    if (my_hover_effect(win, buttons[12]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem2 = my_strdup("God Save Me");
        scenes->insert_val = false;
        usleep(300000);
        scenes->insert = true;
    }
    if (my_hover_effect(win, buttons[13]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem2 = my_strdup("Crybaby");
        scenes->insert_val = false;
        usleep(300000);
        scenes->insert = true;
    }
    if (my_hover_effect(win, buttons[14]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem2 = my_strdup("Save that Shit");
        scenes->insert_val = false;
        usleep(300000);
        scenes->insert = true;
    }
    if (my_hover_effect(win, buttons[15]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem2 = my_strdup("Crunchy");
        scenes->insert_val = false;
        usleep(300000);
        scenes->insert = true;
    }
    if (my_hover_effect(win, buttons[16]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem2 = my_strdup("Croustillant");
        scenes->insert_val = false;
        usleep(300000);
        scenes->insert = true;
    }
    if (my_hover_effect(win, buttons[17]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem2 = my_strdup("Niglo");
        scenes->insert_val = false;
        usleep(300000);
        scenes->insert = true;
    }
    if (my_hover_effect(win, buttons[18]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem2 = my_strdup("Pumpkin !");
        scenes->insert_val = false;
        usleep(300000);
        scenes->insert = true;
    }
    if (my_hover_effect(win, buttons[19]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
        *elem2 = my_strdup("End of the Show");
        scenes->insert_val = false;
        usleep(300000);
        scenes->insert = true;
    }
}

static sfText **create_blocks(void)
{
    sfText **button = malloc(sizeof(sfText *) * 9);
    sfFont *font = sfFont_createFromFile("./assets/old.ttf");

    button[0] = sfText_create();
    sfText_setFont(button[0], font);
    sfText_setCharacterSize(button[0], 45);
    sfText_setColor(button[0], sfBlack);
    sfText_setPosition(button[0], (sfVector2f) {350, 280});
    sfText_setString(button[0], "[0] :   - - - - - - - - - - - - - - - - - ");
    button[1] = sfText_create();
    sfText_setFont(button[1], font);
    sfText_setCharacterSize(button[1], 45);
    sfText_setColor(button[1], sfBlack);
    sfText_setPosition(button[1], (sfVector2f) {350, 350});
    sfText_setString(button[1], "[1] :   - - - - - - - - - - - - - - - - - ");
    button[2] = sfText_create();
    sfText_setFont(button[2], font);
    sfText_setCharacterSize(button[2], 45);
    sfText_setColor(button[2], sfBlack);
    sfText_setPosition(button[2], (sfVector2f) {350, 420});
    sfText_setString(button[2], "[2] :   - - - - - - - - - - - - - - - - - ");
    button[3] = sfText_create();
    sfText_setFont(button[3], font);
    sfText_setCharacterSize(button[3], 45);
    sfText_setColor(button[3], sfBlack);
    sfText_setPosition(button[3], (sfVector2f) {350, 500});
    sfText_setString(button[3], "[3] :   - - - - - - - - - - - - - - - - - ");
    button[4] = sfText_create();
    sfText_setFont(button[4], font);
    sfText_setCharacterSize(button[4], 45);
    sfText_setColor(button[4], sfBlack);
    sfText_setPosition(button[4], (sfVector2f) {350, 580});
    sfText_setString(button[4], "[4] :   - - - - - - - - - - - - - - - - - ");
    button[5] = sfText_create();
    sfText_setFont(button[5], font);
    sfText_setCharacterSize(button[5], 45);
    sfText_setColor(button[5], sfBlack);
    sfText_setPosition(button[5], (sfVector2f) {350, 650});
    sfText_setString(button[5], "[5] :   - - - - - - - - - - - - - - - - - ");
    button[6] = sfText_create();
    sfText_setFont(button[6], font);
    sfText_setCharacterSize(button[6], 45);
    sfText_setColor(button[6], sfBlack);
    sfText_setPosition(button[6], (sfVector2f) {350, 720});
    sfText_setString(button[6], "[6] :   - - - - - - - - - - - - - - - - - ");
    button[7] = sfText_create();
    sfText_setFont(button[7], font);
    sfText_setCharacterSize(button[7], 45);
    sfText_setColor(button[7], sfBlack);
    sfText_setPosition(button[7], (sfVector2f) {350, 800});
    sfText_setString(button[7], "[7] :   - - - - - - - - - - - - - - - - - ");
    button[8] = sfText_create();
    sfText_setFont(button[8], font);
    sfText_setCharacterSize(button[8], 45);
    sfText_setColor(button[8], sfBlack);
    sfText_setPosition(button[8], (sfVector2f) {350, 880});
    sfText_setString(button[8], "[8] :   - - - - - - - - - - - - - - - - - ");
    return (button);
}

int main(int argc, char **argv)
{
    if (argc == 2) {
        if (my_strcmp(argv[1], "-h") == 0 || my_strcmp(argv[1], "--help") == 0) {
            helper(argc, argv);
            return 0;
        }
        return 84;
    } else if (argc == 1) {
        scenes_t scenes = {true, false, false, false, false, false, false, false, 0};
        hashtable_t *hashtable;
        sfVideoMode mode = {1920, 1080, 32};
        sfEvent event;
        sfRenderWindow *win = sfRenderWindow_create(mode, "Secured", sfResize | sfClose, NULL);
        sfRectangleShape *bckgrd = sfRectangleShape_create();
        sfRectangleShape *button_new_ht = sfRectangleShape_create();
        sfText *text_new_ht = sfText_create();
        sfRectangleShape **size_buttons = malloc(sizeof(sfRectangleShape *) * 9);
        sfRectangleShape *delete = delete_button();
        sfText *delete_text = destroy_text();
        sfText *size_displayed = sfText_create();
        sfText *indicator = sfText_create();
        sfTexture *mais = sfTexture_createFromFile("./assets/assets_secured/big(1).jpg", NULL);
        sfSprite *main = sfSprite_create();
        sfTexture *shelfs = sfTexture_createFromFile("./assets/assets_secured/desk.jpg", NULL);
        sfSprite *shelft = sfSprite_create();
        sfTexture *t1 = sfTexture_createFromFile("./assets/assets_secured/book.png", NULL);
        sfTexture *t2 = sfTexture_createFromFile("./assets/assets_secured/topbook.jpg", NULL);
        sfSprite *t3 = sfSprite_create();
        sfFont *font = sfFont_createFromFile("./assets/old.ttf");
        sfRectangleShape *delkey_bu = delkey_button();
        sfText *delkey = delkey_text();
        sfRectangleShape *dump = dump_button();
        sfText *dumping = dump_text();
        sfRectangleShape *insert = insert_button();
        sfText *inserting = insert_text();
        sfRectangleShape *search = search_button();
        sfText *searching = search_text();
        sfRectangleShape **keys = several_keys();
        sfRectangleShape **val = several_keys();
        sfText *select_your_key = sfText_create();
        sfText *select_your_val = sfText_create();
        sfText **our_keys = name_keys();
        sfText **our_val = name_val();
        sfText **blocks = create_blocks();
        sfText *this_key = sfText_create();
        sfText *this_hash = sfText_create();
        sfText *this_value = sfText_create();
        sfColor cool = {96, 43, 40, 255};
        sfText *ind = sfText_create();
        sfTexture *blankt = sfTexture_createFromFile("./assets/blank.jpg", NULL);
        sfSprite *blanks = sfSprite_create();
        sfText **size_texts = malloc(sizeof(sfText *) * 9);
        char *elem = NULL;
        char *elem2 = NULL;
        char *search_elem = NULL;
        char *my_deletion = NULL;
        int nb_search = 0;

        sfSprite_setTexture(main, mais, sfTrue);
        sfSprite_setTexture(blanks, blankt, sfTrue);
        sfSprite_setTexture(shelft, shelfs, sfTrue);
        sfSprite_setTexture(t3, t2, sfTrue);
        sfRenderWindow_setFramerateLimit(win, 60);
        sfRectangleShape_setSize(bckgrd, (sfVector2f) {1920, 1080});
        sfRectangleShape_setPosition(bckgrd, (sfVector2f) {0, 0});
        sfRectangleShape_setFillColor(bckgrd, (sfColor) {180, 180, 180, 255});
        sfText_setFont(indicator, font);
        sfText_setCharacterSize(indicator, 50);
        sfText_setColor(indicator, cool);
        sfText_setPosition(indicator, (sfVector2f) {410, 200});
        sfText_setString(indicator, "C u r r e n t  s i z e :");
        sfText_setFont(ind, font);
        sfText_setCharacterSize(ind, 70);
        sfText_setColor(ind, sfBlack);
        sfText_setPosition(ind, (sfVector2f) {1000, 180});
        sfText_setString(ind, "S u m m a r y :");
        sfText_setFont(select_your_key, font);
        sfText_setCharacterSize(select_your_key, 75);
        sfText_setColor(select_your_key, sfBlack);
        sfText_setPosition(select_your_key, (sfVector2f) {550, 100});
        sfText_setString(select_your_key, "S e l e c t  y o u r  K e y :");
        sfText_setFont(select_your_val, font);
        sfText_setCharacterSize(select_your_val, 75);
        sfText_setColor(select_your_val, sfBlack);
        sfText_setPosition(select_your_val, (sfVector2f) {550, 50});
        sfText_setString(select_your_val, "S e l e c t  y o u r  v a l u e :");
        sfText_setFont(this_key, font);
        sfText_setCharacterSize(this_key, 50);
        sfText_setColor(this_key, sfBlack);
        sfText_setPosition(this_key, (sfVector2f) {320, 50});
        sfText_setString(this_key, "F o r  k e y :                                  V a l u e  i s :");
        sfText_setFont(this_hash, font);
        sfText_setCharacterSize(this_hash, 50);
        sfText_setColor(this_hash, sfYellow);
        sfText_setPosition(this_hash, (sfVector2f) {600, 50});
        sfText_setFont(this_value, font);
        sfText_setCharacterSize(this_value, 50);
        sfText_setColor(this_value, sfRed);
        sfText_setPosition(this_value, (sfVector2f) {1400, 50});
        empty_scene(&button_new_ht, &text_new_ht);
        size_buttons = size_button(size_buttons);
        size_texts = book_text(size_texts);
        while (sfRenderWindow_isOpen(win)) {
            while (sfRenderWindow_pollEvent(win, &event)) {
                if (event.type == sfEvtClosed)
                    sfRenderWindow_close(win);
            }
            sfRenderWindow_clear(win, sfBlack);
            sfRenderWindow_drawRectangleShape(win, bckgrd, NULL);
            if (scenes.no_ht) {
                if (my_hover_effect(win, button_new_ht) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
                    scenes.no_ht = false;
                    scenes.ht_size = true;
                    usleep(300000);
                }
                sfRenderWindow_drawSprite(win, main, NULL);
                sfRenderWindow_drawRectangleShape(win, button_new_ht, NULL);
                sfRenderWindow_drawText(win, text_new_ht, NULL);
            }
            if (scenes.ht_size) {
                sfRenderWindow_drawSprite(win, shelft, NULL);
                sfRectangleShape_setPosition(size_buttons[0], (sfVector2f) {500, 100});
                sfRectangleShape_setPosition(size_buttons[1], (sfVector2f) {850, 100});
                sfRectangleShape_setPosition(size_buttons[2], (sfVector2f) {1200, 100});
                sfRectangleShape_setPosition(size_buttons[3], (sfVector2f) {500, 400});
                sfRectangleShape_setPosition(size_buttons[4], (sfVector2f) {850, 400});
                sfRectangleShape_setPosition(size_buttons[5], (sfVector2f) {1200, 400});
                sfRectangleShape_setPosition(size_buttons[6], (sfVector2f) {500, 700});
                sfRectangleShape_setPosition(size_buttons[7], (sfVector2f) {850, 700});
                sfRectangleShape_setPosition(size_buttons[8], (sfVector2f) {1200, 700});
                sfRectangleShape_setTexture(size_buttons[0], t1, sfTrue);
                sfRectangleShape_setTexture(size_buttons[1], t1, sfTrue);
                sfRectangleShape_setTexture(size_buttons[2], t1, sfTrue);
                sfRectangleShape_setTexture(size_buttons[3], t1, sfTrue);
                sfRectangleShape_setTexture(size_buttons[4], t1, sfTrue);
                sfRectangleShape_setTexture(size_buttons[5], t1, sfTrue);
                sfRectangleShape_setTexture(size_buttons[6], t1, sfTrue);
                sfRectangleShape_setTexture(size_buttons[7], t1, sfTrue);
                sfRectangleShape_setTexture(size_buttons[8], t1, sfTrue);
                sfText_setPosition(size_texts[0], (sfVector2f) {595, 150});
                sfText_setPosition(size_texts[1], (sfVector2f) {935, 150});
                sfText_setPosition(size_texts[2], (sfVector2f) {1290,150});
                sfText_setPosition(size_texts[3], (sfVector2f) {595, 450});
                sfText_setPosition(size_texts[4], (sfVector2f) {935, 450});
                sfText_setPosition(size_texts[5], (sfVector2f) {1290, 450});
                sfText_setPosition(size_texts[6], (sfVector2f) {595, 750});
                sfText_setPosition(size_texts[7], (sfVector2f) {935, 750});
                sfText_setPosition(size_texts[8], (sfVector2f) {1290, 750});
                if (my_hover_effect(win, size_buttons[0]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
                    hashtable = new_hashtable(&hash, 1);
                    scenes.ht_size = false;
                    scenes.ht = true;
                    usleep(300000);
                }
                if (my_hover_effect(win, size_buttons[1]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
                    hashtable = new_hashtable(&hash, 2);
                    scenes.ht_size = false;
                    scenes.ht = true;
                    usleep(300000);
                }
                if (my_hover_effect(win, size_buttons[2]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
                    hashtable = new_hashtable(&hash, 3);
                    scenes.ht_size = false;
                    scenes.ht = true;
                    usleep(300000);
                }
                if (my_hover_effect(win, size_buttons[3]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
                    hashtable = new_hashtable(&hash, 4);
                    scenes.ht_size = false;
                    scenes.ht = true;
                    usleep(300000);
                }
                if (my_hover_effect(win, size_buttons[4]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
                    hashtable = new_hashtable(&hash, 5);
                    scenes.ht_size = false;
                    scenes.ht = true;
                    usleep(300000);
                }
                if (my_hover_effect(win, size_buttons[5]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
                    hashtable = new_hashtable(&hash, 6);
                    scenes.ht_size = false;
                    scenes.ht = true;
                    usleep(300000);
                }
                if (my_hover_effect(win, size_buttons[6]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
                    hashtable = new_hashtable(&hash, 7);
                    scenes.ht_size = false;
                    scenes.ht = true;
                    usleep(300000);
                }
                if (my_hover_effect(win, size_buttons[7]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
                    hashtable = new_hashtable(&hash, 8);
                    scenes.ht_size = false;
                    scenes.ht = true;
                    usleep(300000);
                }
                if (my_hover_effect(win, size_buttons[8]) == 1 && sfMouse_isButtonPressed(sfMouseLeft)) {
                    hashtable = new_hashtable(&hash, 9);
                    scenes.ht_size = false;
                    scenes.ht = true;
                    usleep(300000);
                }
                for (int i = 0; i < 9; i++)
                    sfRenderWindow_drawRectangleShape(win, size_buttons[i], NULL);
                for (int j = 0; j < 9; j++)
                    sfRenderWindow_drawText(win, size_texts[j], NULL);
            }
            if (scenes.ht == true) {
                sfRenderWindow_drawSprite(win, t3, NULL);
                if (my_hover_effect(win, delete) == 1) {
                    if (sfMouse_isButtonPressed(sfMouseLeft)) {
                        delete_hashtable(hashtable);
                        scenes.ht = false;
                        scenes.elem = 0;
                        nb_search = 0;
                        scenes.no_ht = true;
                        usleep(300000);
                    }
                    sfText_setColor(delete_text, sfRed);
                } else {
                    sfText_setColor(delete_text, sfBlack);
                }
                if (my_hover_effect(win, insert) == 1) {
                    if (sfMouse_isButtonPressed(sfMouseLeft)) {
                        scenes.ht = false;
                        scenes.insert_key = true;
                        usleep(300000);
                    }
                    sfText_setColor(inserting, (sfColor) {0, 115, 133, 255});
                } else {
                    sfText_setColor(inserting, sfBlack);
                }
                if (my_hover_effect(win, dump) == 1) {
                    if (sfMouse_isButtonPressed(sfMouseLeft)) {
                        ht_dump(hashtable);
                        usleep(300000);
                    }
                    sfText_setColor(dumping, (sfColor) {0, 115, 133, 255});
                } else {
                    sfText_setColor(dumping, sfBlack);
                }
                if (my_hover_effect(win, delkey_bu) == 1 && scenes.elem > 0) {
                    if (sfMouse_isButtonPressed(sfMouseLeft)) {
                        scenes.ht = false;
                        scenes.delkey = true;
                        usleep(300000);
                    }
                    sfText_setColor(delkey, (sfColor) {0, 115, 133, 255});
                } else {
                    sfText_setColor(delkey, sfBlack);
                }
                if (my_hover_effect(win, search) == 1 && scenes.elem > 0) {
                    if (sfMouse_isButtonPressed(sfMouseLeft)) {
                        scenes.ht = false;
                        scenes.search = true;
                        usleep(300000);
                    }
                    sfText_setColor(searching, (sfColor) {0, 115, 133, 255});
                } else {
                    sfText_setColor(searching, sfBlack);
                }
                size_displayed = size_hashtable(size_displayed, hashtable);
                for (int i = 0; i < 9; i++) {
                    if (i >= hashtable->size) {
                        sfText_setColor(blocks[i], (sfColor) {100, 100, 100, 255});
                    } else {
                        sfText_setColor(blocks[i], sfBlack);
                    }
                    sfRenderWindow_drawText(win, blocks[i], NULL);
                }
                if (nb_search > 0) {
                    sfText_setString(this_hash, search_elem);
                    if (ht_search(hashtable, search_elem) == NULL)
                        sfText_setString(this_value, "NONE");
                    else
                        sfText_setString(this_value, ht_search(hashtable, search_elem));
                    sfText_setString(this_hash, search_elem);
                    sfRenderWindow_drawText(win, this_hash, NULL);
                    sfRenderWindow_drawText(win, this_value, NULL);
                    sfRenderWindow_drawText(win, this_key, NULL);
                }
                sfRenderWindow_drawText(win, size_displayed, NULL);
                sfRenderWindow_drawRectangleShape(win, delete, NULL);
                sfRenderWindow_drawRectangleShape(win, delkey_bu, NULL);
                sfRenderWindow_drawRectangleShape(win, dump, NULL);
                sfRenderWindow_drawRectangleShape(win, insert, NULL);
                sfRenderWindow_drawRectangleShape(win, search, NULL);
                sfRenderWindow_drawText(win, indicator, NULL);
                sfRenderWindow_drawText(win, ind, NULL);
                sfRenderWindow_drawText(win, size_displayed, NULL);
                sfRenderWindow_drawText(win, delete_text, NULL);
                sfRenderWindow_drawText(win, delkey, NULL);
                sfRenderWindow_drawText(win, dumping, NULL);
                sfRenderWindow_drawText(win, inserting, NULL);
                sfRenderWindow_drawText(win, searching, NULL);
            }
            if (scenes.insert_key == true) {
                sfRenderWindow_drawSprite(win, blanks, NULL);
                sfRectangleShape_setPosition(keys[0], (sfVector2f) {80, 250});
                sfRectangleShape_setPosition(keys[1], (sfVector2f) {80, 400});
                sfRectangleShape_setPosition(keys[2], (sfVector2f) {80, 550});
                sfRectangleShape_setPosition(keys[3], (sfVector2f) {80, 700});
                sfRectangleShape_setPosition(keys[4], (sfVector2f) {80, 850});
                sfRectangleShape_setPosition(keys[5], (sfVector2f) {530, 250});
                sfRectangleShape_setPosition(keys[6], (sfVector2f) {530, 400});
                sfRectangleShape_setPosition(keys[7], (sfVector2f) {530, 550});
                sfRectangleShape_setPosition(keys[8], (sfVector2f) {530, 700});
                sfRectangleShape_setPosition(keys[9], (sfVector2f) {530, 850});
                sfRectangleShape_setPosition(keys[10], (sfVector2f) {980, 250});
                sfRectangleShape_setPosition(keys[11], (sfVector2f) {980, 400});
                sfRectangleShape_setPosition(keys[12], (sfVector2f) {980, 550});
                sfRectangleShape_setPosition(keys[13], (sfVector2f) {980, 700});
                sfRectangleShape_setPosition(keys[14], (sfVector2f) {980, 850});
                sfRectangleShape_setPosition(keys[15], (sfVector2f) {1430, 250});
                sfRectangleShape_setPosition(keys[16], (sfVector2f) {1430, 400});
                sfRectangleShape_setPosition(keys[17], (sfVector2f) {1430, 550});
                sfRectangleShape_setPosition(keys[18], (sfVector2f) {1430, 700});
                sfRectangleShape_setPosition(keys[19], (sfVector2f) {1430, 850});
                sfRenderWindow_drawText(win, select_your_key, NULL);
                key_key(&scenes, win, keys, &elem);
                for (int i = 0; i < 20; i++) {
                    sfRenderWindow_drawRectangleShape(win, keys[i], NULL);
                    sfRenderWindow_drawText(win, our_keys[i], NULL);
                }
            }
            if (scenes.insert_val == true) {
                sfRenderWindow_drawSprite(win, blanks, NULL);
                sfRectangleShape_setPosition(val[0], (sfVector2f) {80, 250});
                sfRectangleShape_setPosition(val[1], (sfVector2f) {80, 400});
                sfRectangleShape_setPosition(val[2], (sfVector2f) {80, 550});
                sfRectangleShape_setPosition(val[3], (sfVector2f) {80, 700});
                sfRectangleShape_setPosition(val[4], (sfVector2f) {80, 850});
                sfRectangleShape_setPosition(val[5], (sfVector2f) {530, 250});
                sfRectangleShape_setPosition(val[6], (sfVector2f) {530, 400});
                sfRectangleShape_setPosition(val[7], (sfVector2f) {530, 550});
                sfRectangleShape_setPosition(val[8], (sfVector2f) {530, 700});
                sfRectangleShape_setPosition(val[9], (sfVector2f) {530, 850});
                sfRectangleShape_setPosition(val[10], (sfVector2f) {980, 250});
                sfRectangleShape_setPosition(val[11], (sfVector2f) {980, 400});
                sfRectangleShape_setPosition(val[12], (sfVector2f) {980, 550});
                sfRectangleShape_setPosition(val[13], (sfVector2f) {980, 700});
                sfRectangleShape_setPosition(val[14], (sfVector2f) {980, 850});
                sfRectangleShape_setPosition(val[15], (sfVector2f) {1430, 250});
                sfRectangleShape_setPosition(val[16], (sfVector2f) {1430, 400});
                sfRectangleShape_setPosition(val[17], (sfVector2f) {1430, 550});
                sfRectangleShape_setPosition(val[18], (sfVector2f) {1430, 700});
                sfRectangleShape_setPosition(val[19], (sfVector2f) {1430, 850});
                sfRenderWindow_drawText(win, select_your_val, NULL);
                val_val(&scenes, win, val, &elem2);
                for (int i = 0; i < 20; i++) {
                    sfRenderWindow_drawRectangleShape(win, val[i], NULL);;
                    sfRenderWindow_drawText(win, our_val[i], NULL);
                }
            }
            if (scenes.insert == true) {
                if (ht_insert(hashtable, elem, elem2) == 84)
                    return 84;
                scenes.elem++;
                scenes.insert = false;
                scenes.ht = true;
            }
            if (scenes.search == true) {
                sfRectangleShape_setPosition(keys[0], (sfVector2f) {80, 250});
                sfRectangleShape_setPosition(keys[1], (sfVector2f) {80, 400});
                sfRectangleShape_setPosition(keys[2], (sfVector2f) {80, 550});
                sfRectangleShape_setPosition(keys[3], (sfVector2f) {80, 700});
                sfRectangleShape_setPosition(keys[4], (sfVector2f) {80, 850});
                sfRectangleShape_setPosition(keys[5], (sfVector2f) {530, 250});
                sfRectangleShape_setPosition(keys[6], (sfVector2f) {530, 400});
                sfRectangleShape_setPosition(keys[7], (sfVector2f) {530, 550});
                sfRectangleShape_setPosition(keys[8], (sfVector2f) {530, 700});
                sfRectangleShape_setPosition(keys[9], (sfVector2f) {530, 850});
                sfRectangleShape_setPosition(keys[10], (sfVector2f) {980, 250});
                sfRectangleShape_setPosition(keys[11], (sfVector2f) {980, 400});
                sfRectangleShape_setPosition(keys[12], (sfVector2f) {980, 550});
                sfRectangleShape_setPosition(keys[13], (sfVector2f) {980, 700});
                sfRectangleShape_setPosition(keys[14], (sfVector2f) {980, 850});
                sfRectangleShape_setPosition(keys[15], (sfVector2f) {1430, 250});
                sfRectangleShape_setPosition(keys[16], (sfVector2f) {1430, 400});
                sfRectangleShape_setPosition(keys[17], (sfVector2f) {1430, 550});
                sfRectangleShape_setPosition(keys[18], (sfVector2f) {1430, 700});
                sfRectangleShape_setPosition(keys[19], (sfVector2f) {1430, 850});
                sfRenderWindow_drawText(win, select_your_key, NULL);
                key_search(&scenes, win, keys, &search_elem, &nb_search);
                for (int i = 0; i < 20; i++) {
                    sfRenderWindow_drawRectangleShape(win, keys[i], NULL);
                    sfRenderWindow_drawText(win, our_keys[i], NULL);
                }
            }
            if (scenes.delkey == true) {
                sfRectangleShape_setPosition(keys[0], (sfVector2f) {80, 250});
                sfRectangleShape_setPosition(keys[1], (sfVector2f) {80, 400});
                sfRectangleShape_setPosition(keys[2], (sfVector2f) {80, 550});
                sfRectangleShape_setPosition(keys[3], (sfVector2f) {80, 700});
                sfRectangleShape_setPosition(keys[4], (sfVector2f) {80, 850});
                sfRectangleShape_setPosition(keys[5], (sfVector2f) {530, 250});
                sfRectangleShape_setPosition(keys[6], (sfVector2f) {530, 400});
                sfRectangleShape_setPosition(keys[7], (sfVector2f) {530, 550});
                sfRectangleShape_setPosition(keys[8], (sfVector2f) {530, 700});
                sfRectangleShape_setPosition(keys[9], (sfVector2f) {530, 850});
                sfRectangleShape_setPosition(keys[10], (sfVector2f) {980, 250});
                sfRectangleShape_setPosition(keys[11], (sfVector2f) {980, 400});
                sfRectangleShape_setPosition(keys[12], (sfVector2f) {980, 550});
                sfRectangleShape_setPosition(keys[13], (sfVector2f) {980, 700});
                sfRectangleShape_setPosition(keys[14], (sfVector2f) {980, 850});
                sfRectangleShape_setPosition(keys[15], (sfVector2f) {1430, 250});
                sfRectangleShape_setPosition(keys[16], (sfVector2f) {1430, 400});
                sfRectangleShape_setPosition(keys[17], (sfVector2f) {1430, 550});
                sfRectangleShape_setPosition(keys[18], (sfVector2f) {1430, 700});
                sfRectangleShape_setPosition(keys[19], (sfVector2f) {1430, 850});
                sfRenderWindow_drawText(win, select_your_key, NULL);
                key_delete(&scenes, win, keys, &my_deletion);
                for (int i = 0; i < 20; i++) {
                    sfRenderWindow_drawRectangleShape(win, keys[i], NULL);
                    sfRenderWindow_drawText(win, our_keys[i], NULL);
                }
            }
            if (scenes.deletion == true) {
                ht_delete(hashtable, my_deletion);
                scenes.deletion = false;
                scenes.ht = true;
            }
            sfRenderWindow_display(win);
        }
    }
    return 0;
}
