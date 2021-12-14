/*
** EPITECH PROJECT, 2018
** CSFML
** File description:
** test CSFML
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left = rect->left + offset;
    if (rect->left >= max_value)
        rect->left = 0;
}

int main()
{
    sfRenderWindow *window;
    sfSprite *sprite;
    sfSprite *sprite2;
    sfSprite *sprite3;
    sfTexture *texture;
    sfTexture *texture2;
    sfTexture *texture3;
    sfVideoMode square;
    sfEvent event;
    sfSoundBuffer *soundbuffer;
    sfSoundBuffer *soundbuffer2;
    sfSound *sound;
    sfSound *sound2;
    sfIntRect rect;
    sfIntRect rect2;
    sfVector2f vec = {0.3,0};
    sfVector2f pos = {-400,0};
    sfVector2f spriteP;
    sfVector2i cursorP;
    sfClock *clock;
    sfTime time;
    float seconds;

    square.width = 1086;
    square.height = 671;
    square.bitsPerPixel = 32;

    window = sfRenderWindow_create(square, "My_Infinity_War", sfDefaultStyle, NULL);
    sfRenderWindow_display(window);
    soundbuffer = sfSoundBuffer_createFromFile("bonus/Avengers Theme 8 bit.ogg");
    soundbuffer2 = sfSoundBuffer_createFromFile("bonus/snap.ogg");
    texture = sfTexture_createFromFile("bonus/background.png", NULL);
    texture2 = sfTexture_createFromFile("bonus/Sprite_Sheet/sprite.png", NULL);
    texture3 =sfTexture_createFromFile("bonus/Sprite_Sheet/snap.png",NULL);
    sound = sfSound_create();
    sound2 = sfSound_create();
    sfSound_setBuffer(sound, soundbuffer);
    sfSound_setBuffer(sound2, soundbuffer2);
    sprite = sfSprite_create();
    sprite2 = sfSprite_create();
    sprite3 = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTexture(sprite2, texture2, sfTrue);
    sfSprite_setTexture(sprite3, texture3, sfTrue);
    sfSound_play(sound);
    clock = sfClock_create();

    rect.top = 0;
    rect.left = 0;
    rect.width = 246;
    rect.height = 118;
    rect2.top = 0;
    rect2.left = 0;
    rect2.width = 50;
    rect2.height = 98;

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_display(window);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_drawSprite(window, sprite2, NULL);
        sfRenderWindow_drawSprite(window, sprite3, NULL);
        sfRenderWindow_setMouseCursorVisible(window, sfFalse);
        sfSprite_move(sprite2, vec);
        move_rect(&rect, 246, 738);
        sfSprite_setTextureRect(sprite2, rect);
        sfSprite_setTextureRect(sprite3, rect2);
        if (sfSprite_getPosition(sprite2).x > 1086)
            sfSprite_setPosition(sprite2, pos);

        while (sfRenderWindow_pollEvent(window, &event)) {
            cursorP = sfMouse_getPositionRenderWindow(window);
            spriteP.x = cursorP.x;
            spriteP.y = cursorP.y;
            pos.y = rand() % 550;
            sfSprite_setPosition(sprite3, spriteP);
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            if (!(event.type == sfEvtMouseButtonPressed))
                move_rect(&rect2, 50, 50);
            if (event.type == sfEvtMouseButtonPressed) {
                move_rect(&rect2, 50, 100);
                sfSound_play(sound2);
            }
            time = sfClock_getElapsedTime(clock);
            seconds = time.microseconds / 1000000.0;
            if (seconds  > 3) {
                move_rect(&rect2, 50, 100);
                sfClock_restart(clock);
            }
            if (sfMouse_getPositionRenderWindow(window).x <= (sfSprite_getPosition(sprite2).x + 246)
                && sfMouse_getPositionRenderWindow(window).x >= sfSprite_getPosition(sprite2).x
                && sfMouse_getPositionRenderWindow(window).y <= (sfSprite_getPosition(sprite2).y + 118)
                && sfMouse_getPositionRenderWindow(window).y >= sfSprite_getPosition(sprite2).y) {
                if (event.type == sfEvtMouseButtonPressed)
                    sfSprite_setPosition(sprite2, pos);
            }
        }
    }
    sfTexture_destroy(texture);
    sfTexture_destroy(texture2);
    sfTexture_destroy(texture3);
    sfSprite_destroy(sprite);
    sfSprite_destroy(sprite2);
    sfSprite_destroy(sprite3);
    sfSound_destroy(sound);
    sfSound_destroy(sound2);
    sfSoundBuffer_destroy(soundbuffer);
    sfSoundBuffer_destroy(soundbuffer2);
    sfRenderWindow_destroy(window);
    return(0);
}
