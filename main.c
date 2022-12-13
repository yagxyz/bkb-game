/* Copyright (C) 2016 Marcelo Serrano Zanetti - All Rights Reserved

 * Licensed under the GNU GPL V3.0 license. All conditions apply.

 * Powered by Allegro: http://liballeg.org/license.html

 */



#include <stdio.h>

#include <time.h>

#include <allegro5/allegro.h>

#include <allegro5/allegro_image.h>

#include <allegro5/allegro_audio.h>

#include <allegro5/allegro_acodec.h>


const float FPS = 80;

const int SCREEN_W = 1000;

const int SCREEN_H = 700;

const int BOLA_TAMANHO = 30;

const int BLOCO_LARGURA = 100;

const int BLOCO_ALTURA = 30;

const int REBATEDOR_LARGURA = 80;
const int REBATEDOR_ALTURA = 20;

bool audio();

ALLEGRO_SAMPLE *sample = NULL;
ALLEGRO_SAMPLE *musbloc = NULL;
ALLEGRO_SAMPLE *musblocx = NULL;
ALLEGRO_SAMPLE *musrebt = NULL;

ALLEGRO_AUDIO_STREAM *musica = NULL;
ALLEGRO_AUDIO_STREAM *muswin = NULL;
ALLEGRO_AUDIO_STREAM *muswinn1 = NULL;
ALLEGRO_AUDIO_STREAM *muswinn2 = NULL;
ALLEGRO_AUDIO_STREAM *muswinn3 = NULL;
ALLEGRO_AUDIO_STREAM *muswin1 = NULL;
ALLEGRO_AUDIO_STREAM *musover = NULL;



ALLEGRO_DISPLAY *display = NULL;

ALLEGRO_EVENT_QUEUE *event_queue = NULL;

ALLEGRO_TIMER *timer = NULL;


ALLEGRO_BITMAP *bola = NULL;

ALLEGRO_BITMAP *bloquinho = NULL;
ALLEGRO_BITMAP *bloquinho1 = NULL;
ALLEGRO_BITMAP *bloquinho2 = NULL;
ALLEGRO_BITMAP *bloquinho3 = NULL;
ALLEGRO_BITMAP *bloquinho4 = NULL;
ALLEGRO_BITMAP *bloquinho5 = NULL;
ALLEGRO_BITMAP *bloquinho6 = NULL;
ALLEGRO_BITMAP *bloquinho7 = NULL;
ALLEGRO_BITMAP *bloquinho8 = NULL;
ALLEGRO_BITMAP *bloquinho9 = NULL;
ALLEGRO_BITMAP *bloquinho10 = NULL;
ALLEGRO_BITMAP *bloquinho11 = NULL;
ALLEGRO_BITMAP *bloquinho12 = NULL;
ALLEGRO_BITMAP *bloquinho13 = NULL;
ALLEGRO_BITMAP *bloquinho14 = NULL;
ALLEGRO_BITMAP *bloquinho15 = NULL;
ALLEGRO_BITMAP *bloquinho16 = NULL;
ALLEGRO_BITMAP *bloquinho17 = NULL;
ALLEGRO_BITMAP *bloquinho18 = NULL;
ALLEGRO_BITMAP *bloquinho19 = NULL;

ALLEGRO_BITMAP *bloquinhox1 = NULL;
ALLEGRO_BITMAP *bloquinhox2 = NULL;
ALLEGRO_BITMAP *bloquinhox3 = NULL;
ALLEGRO_BITMAP *bloquinhox4 = NULL;
ALLEGRO_BITMAP *bloquinhox5 = NULL;
ALLEGRO_BITMAP *bloquinhox6 = NULL;
ALLEGRO_BITMAP *bloquinhox7 = NULL;
ALLEGRO_BITMAP *bloquinhox8 = NULL;
ALLEGRO_BITMAP *bloquinhox9 = NULL;
ALLEGRO_BITMAP *bloquinhox10 = NULL;

ALLEGRO_BITMAP *rebatedorBase = NULL;

ALLEGRO_BITMAP *background = NULL;
ALLEGRO_BITMAP *background1 = NULL;
ALLEGRO_BITMAP *background2 = NULL;
ALLEGRO_BITMAP *background3 = NULL;
ALLEGRO_BITMAP *background4 = NULL;
ALLEGRO_BITMAP *jogar = NULL;
ALLEGRO_BITMAP *over = NULL;
ALLEGRO_BITMAP *nivel = NULL;
ALLEGRO_BITMAP *nivel1 = NULL;
ALLEGRO_BITMAP *nivel2 = NULL;
ALLEGRO_BITMAP *nivel3 = NULL;
ALLEGRO_BITMAP *fim = NULL;
ALLEGRO_BITMAP *life1 = NULL;
ALLEGRO_BITMAP *life2 = NULL;
ALLEGRO_BITMAP *life3 = NULL;


ALLEGRO_EVENT ev;



int main(int argc, char **argv)

{    printf("==================GNU GENERAL PUBLIC LICENSE==================\n");
     printf("Copyright (C) Free Software Foundation, Inc. <http://fsf.org/>\n");
     printf(" Everyone is permitted to copy and distribute verbatim copies \n");
     printf("  of this license document, but changing it is not allowed. \n\n");

     printf("*=======================[BREAK-BLOCKS]=======================*\n");
     printf("*========================[INSTRUCOES]========================*\n");
     printf("*===============[ESPACO PARA INICIAR E PAUSAR]===============*\n");
     printf("*===========[SETAS DIREITA E ISQUERDA PARA MOVER]============*\n");
     printf("*===================[APERTE ESC PARA SAIR]===================*\n");
     printf("*===================[ADIANTE...BOA SORTE!]===================*\n");

     printf("  'Especiamente dedicado a minha sobrinha de 9 anos Melanie'  \n");
     printf("---********************************************************yag\n");


if(!al_init())
   {fprintf(stderr, "failed to initialize allegro!\n");
      return -1;
      }

     timer = al_create_timer(1.0 / FPS);
   if(!timer)
    {fprintf(stderr, "failed to create timer!\n");
        return -1;
    }

     bool redraw = true;

     al_set_new_display_flags(ALLEGRO_OPENGL | ALLEGRO_WINDOWED);
     display = al_create_display(SCREEN_W, SCREEN_H);

   if(!display)
    {fprintf(stderr, "failed to create display!\n");
        al_destroy_timer(timer);
       return -1;
    }
    if(!al_install_keyboard())
    {fprintf(stderr, "failed to initialize the keyboard!\n");
        return -1;
    }
    if(!al_install_mouse())
    {fprintf(stderr, "failed to initialize the mouse!\n");
       return -1;
    }
    if(!al_init_image_addon())
    {fprintf(stderr, "failed to initialize the image addon!\n");
       return -1;
    }


    if (!audio()) return -1;


    float bola_pos_x = SCREEN_W/2-BOLA_TAMANHO/2;

    float bola_pos_y = SCREEN_H-REBATEDOR_ALTURA-BOLA_TAMANHO-5;

    float bola_vx = 0;

    float bola_vy = 0;

    float bloquinhox1_vx=1;
    float bloquinhox2_vx=2;
    float bloquinhox3_vx=3;


    float backgroundpx=0;
    float backgroundpx1=-1000;
    float backgroundpx2=-1000;
    float backgroundpx3=-1000;
    float backgroundpx4=-1000;


    float fimpx = -1000;
    float fimpy = 0;

    float life1px = 75;
    float life1py = 480;

    float life2px = 480;
    float life2py = 375;

    float life3px = 885;
    float life3py = 280;

    float nivelpx = -1000;
    float nivelpy = 0;

    float nivelpx1 = -1000;
    float nivelpy1 = 0;

    float nivelpx2 = -1000;
    float nivelpy2 = 0;

    float nivelpx3 = -1000;
    float nivelpy3 = 0;

    float overpx = -1000;
    float overpy = 0;

    float jogarpx = 0;
    float jogarpy = 0;


    float bloquinho_pos_x = 0;
    float bloquinho_pos_y = 0;

    float bloquinho1_pos_x = 100;
    float bloquinho1_pos_y = 0;

    float bloquinho2_pos_x = 200;
    float bloquinho2_pos_y = 0;

    float bloquinho3_pos_x = 300;
    float bloquinho3_pos_y = 0;

    float bloquinho4_pos_x = 400;
    float bloquinho4_pos_y = 0;

    float bloquinho5_pos_x = 500;
    float bloquinho5_pos_y = 0;

    float bloquinho6_pos_x = 600;
    float bloquinho6_pos_y = 0;

    float bloquinho7_pos_x = 700;
    float bloquinho7_pos_y = 0;

    float bloquinho8_pos_x = 800;
    float bloquinho8_pos_y = 0;

    float bloquinho9_pos_x = 900;
    float bloquinho9_pos_y = 0;

    float bloquinho10_pos_x = 0;
    float bloquinho10_pos_y = 30;

    float bloquinho11_pos_x = 100;
    float bloquinho11_pos_y = 30;

    float bloquinho12_pos_x = 200;
    float bloquinho12_pos_y = 30;

    float bloquinho13_pos_x = 300;
    float bloquinho13_pos_y = 30;

    float bloquinho14_pos_x = 400;
    float bloquinho14_pos_y = 30;

    float bloquinho15_pos_x = 500;
    float bloquinho15_pos_y = 30;

    float bloquinho16_pos_x = 600;
    float bloquinho16_pos_y = 30;

    float bloquinho17_pos_x = 700;
    float bloquinho17_pos_y = 30;

    float bloquinho18_pos_x = 800;
    float bloquinho18_pos_y = 30;

    float bloquinho19_pos_x = 900;
    float bloquinho19_pos_y = 30;


    float bloquinhox1_pos_x = -100;
    float bloquinhox1_pos_y = 542;

    float bloquinhox2_pos_x = -100;
    float bloquinhox2_pos_y = 441;

    float bloquinhox3_pos_x = -100;
    float bloquinhox3_pos_y = 340;

    float bloquinhox4_pos_x = -100;
    float bloquinhox4_pos_y = 210;

    float bloquinhox5_pos_x = -100;
    float bloquinhox5_pos_y = 160;

    float bloquinhox6_pos_x = -100;
    float bloquinhox6_pos_y = 285;

    float bloquinhox7_pos_x = -100;
    float bloquinhox7_pos_y = 160;

    float bloquinhox8_pos_x = -100;
    float bloquinhox8_pos_y = 210;

    float bloquinhox9_pos_x = -100;
    float bloquinhox9_pos_y = 285;

    float bloquinhox10_pos_x = -100;
    float bloquinhox10_pos_y = 250;


    float rebatedorBase_pos_x = SCREEN_W/ 2.0 - REBATEDOR_LARGURA/ 2.0;

    float rebatedorBase_pos_y = SCREEN_H - REBATEDOR_ALTURA-5;

    float rebatedorBase_vx = 0;

    int numbloc = 20;
    int batevx=0;
    int savebvx=2;
    int savebvy=-5;
    int tec=-1, e=0;
    int vsent, cont=1;
    int prand=0, sent=1;


    bola              =  al_load_bitmap("imagens/bola.png");

    bloquinho      = al_load_bitmap("imagens/bloquinho.png");
    bloquinho1     = al_load_bitmap("imagens/bloquinho.png");
    bloquinho2     = al_load_bitmap("imagens/bloquinho.png");
    bloquinho3     = al_load_bitmap("imagens/bloquinho.png");
    bloquinho4     = al_load_bitmap("imagens/bloquinho.png");
    bloquinho5     = al_load_bitmap("imagens/bloquinho.png");
    bloquinho6     = al_load_bitmap("imagens/bloquinho.png");
    bloquinho7     = al_load_bitmap("imagens/bloquinho.png");
    bloquinho8     = al_load_bitmap("imagens/bloquinho.png");
    bloquinho9     = al_load_bitmap("imagens/bloquinho.png");
    bloquinho10    = al_load_bitmap("imagens/bloquinho.png");
    bloquinho11     = al_load_bitmap("imagens/bloquinho.png");
    bloquinho12     = al_load_bitmap("imagens/bloquinho.png");
    bloquinho13     = al_load_bitmap("imagens/bloquinho.png");
    bloquinho14     = al_load_bitmap("imagens/bloquinho.png");
    bloquinho15     = al_load_bitmap("imagens/bloquinho.png");
    bloquinho16     = al_load_bitmap("imagens/bloquinho.png");
    bloquinho17     = al_load_bitmap("imagens/bloquinho.png");
    bloquinho18     = al_load_bitmap("imagens/bloquinho.png");
    bloquinho19     = al_load_bitmap("imagens/bloquinho.png");

    bloquinhox1     = al_load_bitmap("imagens/bloquinhox.png");
    bloquinhox2     = al_load_bitmap("imagens/bloquinhox.png");
    bloquinhox3     = al_load_bitmap("imagens/bloquinhox.png");
    bloquinhox4     = al_load_bitmap("imagens/bloquinhox.png");
    bloquinhox5     = al_load_bitmap("imagens/bloquinhox.png");
    bloquinhox6     = al_load_bitmap("imagens/bloquinhox.png");
    bloquinhox7     = al_load_bitmap("imagens/bloquinhox.png");
    bloquinhox8     = al_load_bitmap("imagens/bloquinhox.png");
    bloquinhox9     = al_load_bitmap("imagens/bloquinhox.png");
    bloquinhox10    = al_load_bitmap("imagens/bloquinhox.png");

    rebatedorBase  = al_load_bitmap("imagens/rebatedor.png");

    background        = al_load_bitmap("imagens/fondo.png");
    background1        = al_load_bitmap("imagens/fondo1.png");
    background2        = al_load_bitmap("imagens/fondo2.png");
    background3        = al_load_bitmap("imagens/fondo3.png");
    background4        = al_load_bitmap("imagens/fondo4.png");
    jogar        = al_load_bitmap("imagens/imjogar.png");
    over        = al_load_bitmap("imagens/imover.png");
    nivel        = al_load_bitmap("imagens/nivel.png");
    nivel1        = al_load_bitmap("imagens/niv3.png");
    nivel2        = al_load_bitmap("imagens/niv4.png");
    nivel3        = al_load_bitmap("imagens/niv5.png");
    fim        = al_load_bitmap("imagens/imfim.png");
    life1        = al_load_bitmap("imagens/bola.png");
    life2        = al_load_bitmap("imagens/bola.png");
    life3        = al_load_bitmap("imagens/bola.png");

if(!bola)
    {fprintf(stderr, "falhou ao criar a bola bitmap!\n");
        return -1;
    }
    if(!bloquinho)
    {fprintf(stderr, "falhou ao criar o bloquinho bitmap!\n");
        al_destroy_display(display);
        al_destroy_timer(timer);
        al_destroy_bitmap(bola);
        return -1;
    }
   if(!rebatedorBase)
    {fprintf(stderr, "falhou ao criar o rebatedorbase bitmap!\n");
        al_destroy_display(display);
        al_destroy_timer(timer);
        al_destroy_bitmap(bola);
        al_destroy_bitmap(bloquinho);
        return -1;
    }

    if(!background)
    {fprintf(stderr, "falhou ao criar o background bitmap!\n");
        al_destroy_display(display);
        al_destroy_timer(timer);
        al_destroy_bitmap(bola);
        al_destroy_bitmap(bloquinho);
        al_destroy_bitmap(rebatedorBase);
        return -1;
    }
    if(!background1)
    {fprintf(stderr, "falhou ao criar o background bitmap!\n");
        al_destroy_display(display);
        al_destroy_timer(timer);
        al_destroy_bitmap(bola);
        al_destroy_bitmap(bloquinho);
        al_destroy_bitmap(rebatedorBase);
        return -1;
    }
    if(!background2)
    {fprintf(stderr, "falhou ao criar o background bitmap!\n");
        al_destroy_display(display);
        al_destroy_timer(timer);
        al_destroy_bitmap(bola);
        al_destroy_bitmap(bloquinho);
        al_destroy_bitmap(rebatedorBase);
        return -1;
    }
    if(!background3)
    {fprintf(stderr, "falhou ao criar o background bitmap!\n");
        al_destroy_display(display);
        al_destroy_timer(timer);
        al_destroy_bitmap(bola);
        al_destroy_bitmap(bloquinho);
        al_destroy_bitmap(rebatedorBase);
        return -1;
    }
    if(!background4)
    {fprintf(stderr, "falhou ao criar o background bitmap!\n");
        al_destroy_display(display);
        al_destroy_timer(timer);
        al_destroy_bitmap(bola);
        al_destroy_bitmap(bloquinho);
        al_destroy_bitmap(rebatedorBase);
        return -1;
    }

    al_set_target_bitmap(al_get_backbuffer(display));
    event_queue = al_create_event_queue();

if(!event_queue)
    {fprintf(stderr, "failed to create event_queue!\n");
        al_destroy_bitmap(bola);
        al_destroy_bitmap(bloquinho);
        al_destroy_bitmap(rebatedorBase);
        al_destroy_bitmap(background);
        al_destroy_bitmap(background1);
        al_destroy_bitmap(background2);
        al_destroy_bitmap(background3);
        al_destroy_bitmap(background4);
        al_destroy_bitmap(jogar);
        al_destroy_bitmap(over);
        al_destroy_bitmap(nivel);
        al_destroy_bitmap(nivel1);
        al_destroy_bitmap(nivel2);
        al_destroy_bitmap(nivel3);
        al_destroy_bitmap(fim);
        al_destroy_bitmap(life1);
        al_destroy_bitmap(life2);
        al_destroy_bitmap(life3);
        al_destroy_display(display);
        al_destroy_timer(timer);
        return -1;
    }

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());
    al_clear_to_color(al_map_rgb(0,0,0));
    al_flip_display();
    al_start_timer(timer);


    while(1)
    {
        al_wait_for_event(event_queue, &ev);
        if(prand<500){prand=rand()%1000+10;}
        if(prand>=500){prand=rand()%1000-30;}
        if(prand<=0)prand=300;
        vsent=rand()%2;
        if(1==vsent)sent=-1;
        if(0==vsent)sent=1;

        if(ev.type==ALLEGRO_EVENT_KEY_CHAR&&ev.keyboard.keycode==ALLEGRO_KEY_SPACE)
        {
            switch(ev.keyboard.keycode)
            {
            case ALLEGRO_KEY_SPACE:
                if(numbloc<=0&&e==0)
                {
                    life1px=75;
                    life2px=480;
                    life3px=885;
                    jogarpx = 0;
                    nivelpx = -1000;

                bola_pos_x = SCREEN_W/2-BOLA_TAMANHO/2;
                bola_pos_y = SCREEN_H-REBATEDOR_ALTURA-BOLA_TAMANHO-5;
                rebatedorBase_pos_x = SCREEN_W/ 2.0 - REBATEDOR_LARGURA/ 2.0;
                bola_vx = 0;
                bola_vy = 0;
                tec=-1;
                e=1;
                numbloc=20;
                batevx=0;
    bloquinho_pos_x = 0;
    bloquinho_pos_y = 0;

    bloquinho1_pos_x = 100;
    bloquinho1_pos_y = 0;

    bloquinho2_pos_x = 200;
    bloquinho2_pos_y = 0;

    bloquinho3_pos_x = 300;
    bloquinho3_pos_y = 0;

    bloquinho4_pos_x = 400;
    bloquinho4_pos_y = 0;

    bloquinho5_pos_x = 500;
    bloquinho5_pos_y = 0;

    bloquinho6_pos_x = 600;
    bloquinho6_pos_y = 0;

    bloquinho7_pos_x = 700;
    bloquinho7_pos_y = 0;

    bloquinho8_pos_x = 800;
    bloquinho8_pos_y = 0;

    bloquinho9_pos_x = 900;
    bloquinho9_pos_y = 0;

    bloquinho10_pos_x = 0;
    bloquinho10_pos_y = 30;

    bloquinho11_pos_x = 100;
    bloquinho11_pos_y = 30;

    bloquinho12_pos_x = 200;
    bloquinho12_pos_y = 30;

     bloquinho13_pos_x = 300;
     bloquinho13_pos_y = 30;

     bloquinho14_pos_x = 400;
     bloquinho14_pos_y = 30;

     bloquinho15_pos_x = 500;
     bloquinho15_pos_y = 30;

     bloquinho16_pos_x = 600;
     bloquinho16_pos_y = 30;

     bloquinho17_pos_x = 700;
     bloquinho17_pos_y = 30;

     bloquinho18_pos_x = 800;
     bloquinho18_pos_y = 30;

     bloquinho19_pos_x = 900;
     bloquinho19_pos_y = 30;

    bloquinho      = al_load_bitmap("imagens/bloquinho1.png");
    bloquinho1     = al_load_bitmap("imagens/bloquinho1.png");
    bloquinho2     = al_load_bitmap("imagens/bloquinho1.png");
    bloquinho3     = al_load_bitmap("imagens/bloquinho1.png");
    bloquinho4     = al_load_bitmap("imagens/bloquinho1.png");
    bloquinho5     = al_load_bitmap("imagens/bloquinho1.png");
    bloquinho6     = al_load_bitmap("imagens/bloquinho1.png");
    bloquinho7     = al_load_bitmap("imagens/bloquinho1.png");
    bloquinho8     = al_load_bitmap("imagens/bloquinho1.png");
    bloquinho9     = al_load_bitmap("imagens/bloquinho1.png");
    bloquinho10    = al_load_bitmap("imagens/bloquinho1.png");
    bloquinho11     = al_load_bitmap("imagens/bloquinho1.png");
    bloquinho12     = al_load_bitmap("imagens/bloquinho1.png");
    bloquinho13     = al_load_bitmap("imagens/bloquinho1.png");
    bloquinho14     = al_load_bitmap("imagens/bloquinho1.png");
    bloquinho15     = al_load_bitmap("imagens/bloquinho1.png");
    bloquinho16     = al_load_bitmap("imagens/bloquinho1.png");
    bloquinho17     = al_load_bitmap("imagens/bloquinho1.png");
    bloquinho18     = al_load_bitmap("imagens/bloquinho1.png");
    bloquinho19     = al_load_bitmap("imagens/bloquinho1.png");

                }
                if(numbloc<=0&&e==1)
                {
                    life1px=75;
                    life2px=480;
                    life3px=885;
                    jogarpx = 0;
                    nivelpx1 = -1000;

                bola_pos_x = SCREEN_W/2-BOLA_TAMANHO/2;
                bola_pos_y = SCREEN_H-REBATEDOR_ALTURA-BOLA_TAMANHO-5;
                rebatedorBase_pos_x = SCREEN_W/ 2.0 - REBATEDOR_LARGURA/ 2.0;
                bola_vx = 0;
                bola_vy = 0;
                tec=-1;
                e=2;
                numbloc=20;
                batevx=0;
    bloquinho_pos_x = 0;
    bloquinho_pos_y = 0;

    bloquinho1_pos_x = 100;
    bloquinho1_pos_y = 0;

    bloquinho2_pos_x = 200;
    bloquinho2_pos_y = 0;

    bloquinho3_pos_x = 300;
    bloquinho3_pos_y = 0;

    bloquinho4_pos_x = 400;
    bloquinho4_pos_y = 0;

    bloquinho5_pos_x = 500;
    bloquinho5_pos_y = 0;

    bloquinho6_pos_x = 600;
    bloquinho6_pos_y = 0;

    bloquinho7_pos_x = 700;
    bloquinho7_pos_y = 0;

    bloquinho8_pos_x = 800;
    bloquinho8_pos_y = 0;

    bloquinho9_pos_x = 900;
    bloquinho9_pos_y = 0;

    bloquinho10_pos_x = 0;
    bloquinho10_pos_y = 30;

    bloquinho11_pos_x = 100;
    bloquinho11_pos_y = 30;

    bloquinho12_pos_x = 200;
    bloquinho12_pos_y = 30;

     bloquinho13_pos_x = 300;
     bloquinho13_pos_y = 30;

     bloquinho14_pos_x = 400;
     bloquinho14_pos_y = 30;

     bloquinho15_pos_x = 500;
     bloquinho15_pos_y = 30;

     bloquinho16_pos_x = 600;
     bloquinho16_pos_y = 30;

     bloquinho17_pos_x = 700;
     bloquinho17_pos_y = 30;

     bloquinho18_pos_x = 800;
     bloquinho18_pos_y = 30;

     bloquinho19_pos_x = 900;
     bloquinho19_pos_y = 30;

    bloquinho      = al_load_bitmap("imagens/bloquinho2.png");
    bloquinho1     = al_load_bitmap("imagens/bloquinho2.png");
    bloquinho2     = al_load_bitmap("imagens/bloquinho2.png");
    bloquinho3     = al_load_bitmap("imagens/bloquinho2.png");
    bloquinho4     = al_load_bitmap("imagens/bloquinho2.png");
    bloquinho5     = al_load_bitmap("imagens/bloquinho2.png");
    bloquinho6     = al_load_bitmap("imagens/bloquinho2.png");
    bloquinho7     = al_load_bitmap("imagens/bloquinho2.png");
    bloquinho8     = al_load_bitmap("imagens/bloquinho2.png");
    bloquinho9     = al_load_bitmap("imagens/bloquinho2.png");
    bloquinho10    = al_load_bitmap("imagens/bloquinho2.png");
    bloquinho11     = al_load_bitmap("imagens/bloquinho2.png");
    bloquinho12     = al_load_bitmap("imagens/bloquinho2.png");
    bloquinho13     = al_load_bitmap("imagens/bloquinho2.png");
    bloquinho14     = al_load_bitmap("imagens/bloquinho2.png");
    bloquinho15     = al_load_bitmap("imagens/bloquinho2.png");
    bloquinho16     = al_load_bitmap("imagens/bloquinho2.png");
    bloquinho17     = al_load_bitmap("imagens/bloquinho2.png");
    bloquinho18     = al_load_bitmap("imagens/bloquinho2.png");
    bloquinho19     = al_load_bitmap("imagens/bloquinho2.png");

                }

                if(numbloc<=0&&e==2)
                {
                    life1px=75;
                    life2px=480;
                    life3px=885;
                    jogarpx = 0;
                    nivelpx2 = -1000;

                bola_pos_x = SCREEN_W/2-BOLA_TAMANHO/2;
                bola_pos_y = SCREEN_H-REBATEDOR_ALTURA-BOLA_TAMANHO-5;
                rebatedorBase_pos_x = SCREEN_W/ 2.0 - REBATEDOR_LARGURA/ 2.0;
                bola_vx = 0;
                bola_vy = 0;
                tec=-1;
                e=3;
                numbloc=20;
                batevx=0;
    bloquinho_pos_x = 0;
    bloquinho_pos_y = 0;

    bloquinho1_pos_x = 100;
    bloquinho1_pos_y = 0;

    bloquinho2_pos_x = 200;
    bloquinho2_pos_y = 0;

    bloquinho3_pos_x = 300;
    bloquinho3_pos_y = 0;

    bloquinho4_pos_x = 400;
    bloquinho4_pos_y = 0;

    bloquinho5_pos_x = 500;
    bloquinho5_pos_y = 0;

    bloquinho6_pos_x = 600;
    bloquinho6_pos_y = 0;

    bloquinho7_pos_x = 700;
    bloquinho7_pos_y = 0;

    bloquinho8_pos_x = 800;
    bloquinho8_pos_y = 0;

    bloquinho9_pos_x = 900;
    bloquinho9_pos_y = 0;

    bloquinho10_pos_x = 0;
    bloquinho10_pos_y = 30;

    bloquinho11_pos_x = 100;
    bloquinho11_pos_y = 30;

    bloquinho12_pos_x = 200;
    bloquinho12_pos_y = 30;

     bloquinho13_pos_x = 300;
     bloquinho13_pos_y = 30;

     bloquinho14_pos_x = 400;
     bloquinho14_pos_y = 30;

     bloquinho15_pos_x = 500;
     bloquinho15_pos_y = 30;

     bloquinho16_pos_x = 600;
     bloquinho16_pos_y = 30;

     bloquinho17_pos_x = 700;
     bloquinho17_pos_y = 30;

     bloquinho18_pos_x = 800;
     bloquinho18_pos_y = 30;

     bloquinho19_pos_x = 900;
     bloquinho19_pos_y = 30;
                }

                if(numbloc<=0&&e==3)
                {
                    life1px=75;
                    life2px=480;
                    life3px=885;
                    jogarpx = 0;
                    nivelpx3 = -1000;

                bola_pos_x = SCREEN_W/2-BOLA_TAMANHO/2;
                bola_pos_y = SCREEN_H-REBATEDOR_ALTURA-BOLA_TAMANHO-5;
                rebatedorBase_pos_x = SCREEN_W/ 2.0 - REBATEDOR_LARGURA/ 2.0;
                bola_vx = 0;
                bola_vy = 0;
                tec=-1;
                e=4;
                numbloc=20;
                batevx=0;
    bloquinho_pos_x = 0;
    bloquinho_pos_y = 0;

    bloquinho1_pos_x = 100;
    bloquinho1_pos_y = 0;

    bloquinho2_pos_x = 200;
    bloquinho2_pos_y = 0;

    bloquinho3_pos_x = 300;
    bloquinho3_pos_y = 0;

    bloquinho4_pos_x = 400;
    bloquinho4_pos_y = 0;

    bloquinho5_pos_x = 500;
    bloquinho5_pos_y = 0;

    bloquinho6_pos_x = 600;
    bloquinho6_pos_y = 0;

    bloquinho7_pos_x = 700;
    bloquinho7_pos_y = 0;

    bloquinho8_pos_x = 800;
    bloquinho8_pos_y = 0;

    bloquinho9_pos_x = 900;
    bloquinho9_pos_y = 0;

    bloquinho10_pos_x = 0;
    bloquinho10_pos_y = 30;

    bloquinho11_pos_x = 100;
    bloquinho11_pos_y = 30;

    bloquinho12_pos_x = 200;
    bloquinho12_pos_y = 30;

     bloquinho13_pos_x = 300;
     bloquinho13_pos_y = 30;

     bloquinho14_pos_x = 400;
     bloquinho14_pos_y = 30;

     bloquinho15_pos_x = 500;
     bloquinho15_pos_y = 30;

     bloquinho16_pos_x = 600;
     bloquinho16_pos_y = 30;

     bloquinho17_pos_x = 700;
     bloquinho17_pos_y = 30;

     bloquinho18_pos_x = 800;
     bloquinho18_pos_y = 30;

     bloquinho19_pos_x = 900;
     bloquinho19_pos_y = 30;

    bloquinho      = al_load_bitmap("imagens/bloquinho3.png");
    bloquinho1     = al_load_bitmap("imagens/bloquinho3.png");
    bloquinho2     = al_load_bitmap("imagens/bloquinho3.png");
    bloquinho3     = al_load_bitmap("imagens/bloquinho3.png");
    bloquinho4     = al_load_bitmap("imagens/bloquinho3.png");
    bloquinho5     = al_load_bitmap("imagens/bloquinho3.png");
    bloquinho6     = al_load_bitmap("imagens/bloquinho3.png");
    bloquinho7     = al_load_bitmap("imagens/bloquinho3.png");
    bloquinho8     = al_load_bitmap("imagens/bloquinho3.png");
    bloquinho9     = al_load_bitmap("imagens/bloquinho3.png");
    bloquinho10    = al_load_bitmap("imagens/bloquinho3.png");
    bloquinho11     = al_load_bitmap("imagens/bloquinho3.png");
    bloquinho12     = al_load_bitmap("imagens/bloquinho3.png");
    bloquinho13     = al_load_bitmap("imagens/bloquinho3.png");
    bloquinho14     = al_load_bitmap("imagens/bloquinho3.png");
    bloquinho15     = al_load_bitmap("imagens/bloquinho3.png");
    bloquinho16     = al_load_bitmap("imagens/bloquinho3.png");
    bloquinho17     = al_load_bitmap("imagens/bloquinho3.png");
    bloquinho18     = al_load_bitmap("imagens/bloquinho3.png");
    bloquinho19     = al_load_bitmap("imagens/bloquinho3.png");


                }

                if(tec==0)
                {
                    al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());
                    al_set_audio_stream_playing(musica, false);
                    savebvx=bola_vx;
                    savebvy=bola_vy;
                    bola_vx=0;
                    bola_vy=0;
                    tec=1;
                }
              else if(tec==-1)
                {
                    jogarpx = -1000;
                    al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());
                    al_set_audio_stream_playing(musica, true);
                    bola_vx=savebvx*sent;
                    bola_vy=savebvy;
                    tec=0;
                }
                else if(tec==1&&numbloc<=0)
                {
                    tec=1;
                }
                else if(tec==1&&batevx==-1)
                {
                    tec=1;
                }
                else
                {
                    bola_vx=savebvx;
                    bola_vy=savebvy;
                    tec=2;
                }
                break;
            }
        }

else

    if(ev.type == ALLEGRO_EVENT_TIMER)
        {
            if(tec==2)
            {al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());
             al_set_audio_stream_playing(musica, true);
             tec=0;
            }

            if(bola_pos_y < 0)
            {
                bola_vy = -bola_vy;cont=1;
            }
            if(bola_pos_y < 0&&0<bola_pos_y+30)
            {
                bola_pos_y=1;cont=1;
            }

            if(bola_pos_y < rebatedorBase_pos_y&&bola_pos_y+BOLA_TAMANHO>rebatedorBase_pos_y+10&&batevx==0&&e==0)
            {
                bola_pos_x = prand;

                bola_pos_y = SCREEN_H/ 4.0 - BOLA_TAMANHO - REBATEDOR_ALTURA-10;

                bola_vx = 4*sent; bola_vy = 4;
                batevx=2;life3px=-100;cont=1;
            }

             if(bola_pos_y < rebatedorBase_pos_y&&bola_pos_y+BOLA_TAMANHO>rebatedorBase_pos_y+10&&batevx==2&&e==0)
            {
                bola_pos_x = prand;

                bola_pos_y = SCREEN_H/ 4.0 - BOLA_TAMANHO - REBATEDOR_ALTURA-10;

                bola_vx = 3*sent; bola_vy = 4;
                batevx=3;life2px=-100;cont=1;
            }

            if(bola_pos_y < rebatedorBase_pos_y&&bola_pos_y+BOLA_TAMANHO>rebatedorBase_pos_y+10&&batevx==3&&e==0)
            {
                bola_pos_x = prand;

                bola_pos_y = SCREEN_H/ 4.0 - BOLA_TAMANHO - REBATEDOR_ALTURA-10;

                bola_vx = 3*sent; bola_vy = 4;
                batevx=-1;life1px =-100;cont=1;
            }

             if(bola_pos_y < rebatedorBase_pos_y&&bola_pos_y+BOLA_TAMANHO>rebatedorBase_pos_y+10&&batevx==0&&e==1)
            {
                bola_pos_x = prand;

                bola_pos_y = SCREEN_H/ 4.0 - BOLA_TAMANHO - REBATEDOR_ALTURA-10;

                bola_vx = 4*sent; bola_vy = 4;
                batevx=2;life3px=-100;cont=1;
            }

             if(bola_pos_y < rebatedorBase_pos_y&&bola_pos_y+BOLA_TAMANHO>rebatedorBase_pos_y+10&&batevx==2&&e==1)
            {
                bola_pos_x = prand;

                bola_pos_y = SCREEN_H/ 4.0 - BOLA_TAMANHO - REBATEDOR_ALTURA-10;

                bola_vx = 3*sent; bola_vy = 4;
                batevx=3;life2px=-100;cont=1;
            }

            if(bola_pos_y < rebatedorBase_pos_y&&bola_pos_y+BOLA_TAMANHO>rebatedorBase_pos_y+10&&batevx==3&&e==1)
            {
                bola_pos_x = prand;

                bola_pos_y = SCREEN_H/ 4.0 - BOLA_TAMANHO - REBATEDOR_ALTURA-10;

                bola_vx = 4*sent; bola_vy =3;
                batevx=-1;life1px=-100;cont=1;
            }

            if(bola_pos_y < rebatedorBase_pos_y&&bola_pos_y+BOLA_TAMANHO>rebatedorBase_pos_y+10&&batevx==0&&e==2)
            {
                bola_pos_x = prand;

                bola_pos_y = SCREEN_H/ 4.0 - BOLA_TAMANHO - REBATEDOR_ALTURA-10;

                bola_vx = 3*sent; bola_vy = 4;
                batevx=2;life3px=-100;cont=1;
            }

             if(bola_pos_y < rebatedorBase_pos_y&&bola_pos_y+BOLA_TAMANHO>rebatedorBase_pos_y+10&&batevx==2&&e==2)
            {
                bola_pos_x = prand;

                bola_pos_y = SCREEN_H/ 4.0 - BOLA_TAMANHO - REBATEDOR_ALTURA-10;

                bola_vx = 4*sent; bola_vy = 3;
                batevx=3;life2px=-100;cont=1;
            }

            if(bola_pos_y < rebatedorBase_pos_y&&bola_pos_y+BOLA_TAMANHO>rebatedorBase_pos_y+10&&batevx==3&&e==2)
            {
                bola_pos_x = prand;

                bola_pos_y = SCREEN_H/ 4.0 - BOLA_TAMANHO - REBATEDOR_ALTURA-10;

                bola_vx = 3*sent; bola_vy = 4;
                batevx=-1;life1px =-100;cont=1;
            }

             if(bola_pos_y < rebatedorBase_pos_y&&bola_pos_y+BOLA_TAMANHO>rebatedorBase_pos_y+10&&batevx==0&&e==3)
            {
                bola_pos_x = prand;

                bola_pos_y = SCREEN_H/ 4.0 - BOLA_TAMANHO - REBATEDOR_ALTURA-10;

                bola_vx = 4*sent; bola_vy = 4;
                batevx=2;life3px=-100;cont=1;
            }

             if(bola_pos_y < rebatedorBase_pos_y&&bola_pos_y+BOLA_TAMANHO>rebatedorBase_pos_y+10&&batevx==2&&e==3)
            {
                bola_pos_x = prand;

                bola_pos_y = SCREEN_H/ 4.0 - BOLA_TAMANHO - REBATEDOR_ALTURA-10;

                bola_vx = 3*sent; bola_vy = 4;
                batevx=3;life2px=-100;cont=1;
            }

            if(bola_pos_y < rebatedorBase_pos_y&&bola_pos_y+BOLA_TAMANHO>rebatedorBase_pos_y+10&&batevx==3&&e==3)
            {
                bola_pos_x = prand;

                bola_pos_y = SCREEN_H/ 4.0 - BOLA_TAMANHO - REBATEDOR_ALTURA-10;

                bola_vx = 3*sent; bola_vy =3;
                batevx=-1;life1px=-100;cont=1;
            }

            if(bola_pos_y < rebatedorBase_pos_y&&bola_pos_y+BOLA_TAMANHO>rebatedorBase_pos_y+10&&batevx==0&&e==4)
            {
                bola_pos_x = prand;

                bola_pos_y = SCREEN_H/ 4.0 - BOLA_TAMANHO - REBATEDOR_ALTURA-10;

                bola_vx = 3*sent; bola_vy = 3;
                batevx=2;life3px=-100;cont=1;
            }

             if(bola_pos_y < rebatedorBase_pos_y&&bola_pos_y+BOLA_TAMANHO>rebatedorBase_pos_y+10&&batevx==2&&e==4)
            {
                bola_pos_x = prand;

                bola_pos_y = SCREEN_H/ 4.0 - BOLA_TAMANHO - REBATEDOR_ALTURA-10;

                bola_vx = 4*sent; bola_vy = 3;
                batevx=3;life2px=-100;cont=1;
            }

            if(bola_pos_y < rebatedorBase_pos_y&&bola_pos_y+BOLA_TAMANHO>rebatedorBase_pos_y+10&&batevx==3&&e==4)
            {
                bola_pos_x = prand;

                bola_pos_y = SCREEN_H/ 4.0 - BOLA_TAMANHO - REBATEDOR_ALTURA-10;

                bola_vx = 3*sent; bola_vy =3;
                batevx=-1;life1px=-100;cont=1;
            }

            if(bola_pos_y < rebatedorBase_pos_y&&bola_pos_y+BOLA_TAMANHO>rebatedorBase_pos_y+10&&batevx==-1)
            {
                overpx = 0;
                al_attach_audio_stream_to_mixer(musover, al_get_default_mixer());
                al_set_audio_stream_playing(musover, true);
                    al_set_audio_stream_playing(musica, false);

                bola_pos_x = SCREEN_W / 2.0;

                bola_pos_y = SCREEN_H/ 2.0;

                bola_vx = 0; bola_vy = 0;tec=1;cont=0;
            }

            if(numbloc<=0&&e==0)
            {
                nivelpx = 0;
                backgroundpx=-1000;
                backgroundpx1=0;


                al_attach_audio_stream_to_mixer(muswin, al_get_default_mixer());
                al_set_audio_stream_playing(muswin, true);
                al_set_audio_stream_playing(musica, false);

    rebatedorBase  = al_load_bitmap("imagens/rebatedor1.png");
    bloquinhox6_pos_x = 415;
    bloquinhox9_pos_x = 495;

                bola_pos_x = SCREEN_W / 2.0 - BOLA_TAMANHO / 2.0;

                bola_pos_y = SCREEN_H - BOLA_TAMANHO - REBATEDOR_ALTURA-10;

                rebatedorBase_pos_x = SCREEN_W/ 2.0 - REBATEDOR_LARGURA/ 2.0;

                bola_vx = 0; bola_vy = 0;tec=1;cont=1;
            }

            if(numbloc<=0&&e==1)
            {
                nivelpx1 = 0;
                backgroundpx1=-1000;
                backgroundpx2=0;
                rebatedorBase  = al_load_bitmap("imagens/rebatedor.png");

                bloquinhox1_pos_x = 50;

                al_attach_audio_stream_to_mixer(muswinn1, al_get_default_mixer());
                al_set_audio_stream_playing(muswinn1, true);
                al_set_audio_stream_playing(musica, false);

                bola_pos_x = SCREEN_W / 2.0 - BOLA_TAMANHO / 2.0;

                bola_pos_y = SCREEN_H - BOLA_TAMANHO - REBATEDOR_ALTURA-10;

                rebatedorBase_pos_x = SCREEN_W/ 2.0 - REBATEDOR_LARGURA/ 2.0;

                bola_vx = 0; bola_vy = 0;tec=1;cont=1;
            }

            if(numbloc<=0&&e==2)
            {
                nivelpx2 = 0;
                backgroundpx2=-1000;
                backgroundpx3=0;

                al_attach_audio_stream_to_mixer(muswinn2, al_get_default_mixer());
                al_set_audio_stream_playing(muswinn2, true);
                al_set_audio_stream_playing(musica, false);

                bloquinhox1_pos_x = 50;
                bloquinhox3_pos_x = 860;
                bloquinhox5_pos_x = 455;
                bloquinhox7_pos_x = 100;


                bola_pos_x = SCREEN_W / 2.0 - BOLA_TAMANHO / 2.0;

                bola_pos_y = SCREEN_H - BOLA_TAMANHO - REBATEDOR_ALTURA-10;

                rebatedorBase_pos_x = SCREEN_W/ 2.0 - REBATEDOR_LARGURA/ 2.0;

                bola_vx = 0; bola_vy = 0;tec=1;cont=1;
            }

            if(numbloc<=0&&e==3)
            {
                nivelpx3 = 0;
                backgroundpx3=-1000;
                backgroundpx4=0;
                al_attach_audio_stream_to_mixer(muswinn3, al_get_default_mixer());
                al_set_audio_stream_playing(muswinn3, true);
                al_set_audio_stream_playing(musica, false);

                bloquinhox1_pos_x = 50;
                bloquinhox3_pos_x = 860;
                bloquinhox2_pos_x = 455;
                bloquinhox4_pos_x = 335;
                bloquinhox8_pos_x = 575;
                bloquinhox10_pos_x = 920;

                bola_pos_x = SCREEN_W / 2.0 - BOLA_TAMANHO / 2.0;

                bola_pos_y = SCREEN_H - BOLA_TAMANHO - REBATEDOR_ALTURA-10;

                rebatedorBase_pos_x = SCREEN_W/ 2.0 - REBATEDOR_LARGURA/ 2.0;

                bola_vx = 0; bola_vy = 0;tec=1;cont=1;
            }

            if(numbloc<=0&&e==4)
            {
                fimpx = 0;
                al_attach_audio_stream_to_mixer(muswin1, al_get_default_mixer());
                al_set_audio_stream_playing(muswin1, true);
                al_set_audio_stream_playing(musica, false);

                bola_pos_x = SCREEN_W / 2.0 - BOLA_TAMANHO / 2.0-5;

                bola_pos_y = SCREEN_H-90;

                rebatedorBase_pos_x = SCREEN_W/ 2.0 - REBATEDOR_LARGURA/ 2.0;

                bola_vx = 0; bola_vy = 0;

                tec=1;
            }

            if(bola_pos_x < 0 || bola_pos_x > SCREEN_W - BOLA_TAMANHO)
            {
                bola_vx = -bola_vx;cont=1;
            }


            if(cont==1){

            bola =  al_load_bitmap("imagens/bola.png");

            if(bola_pos_y <= bloquinho_pos_y + BLOCO_ALTURA&&bola_pos_y+BOLA_TAMANHO>= bloquinho_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>=bloquinho_pos_x)
                    {if(bola_pos_x<=bloquinho_pos_x + BLOCO_LARGURA)
                       {bola_vy = -bola_vy*1.2;bloquinho_pos_x=-200;numbloc--;
                       al_play_sample(musbloc, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}

            if(bola_pos_y <= bloquinho1_pos_y + BLOCO_ALTURA&&bola_pos_y+BOLA_TAMANHO>= bloquinho1_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>=bloquinho1_pos_x)
                    {if(bola_pos_x<=bloquinho1_pos_x + BLOCO_LARGURA)
                      {bola_vy = -bola_vy;bloquinho1_pos_x=-200;numbloc--;
                      al_play_sample(musbloc, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}

            if(bola_pos_y <= bloquinho2_pos_y + BLOCO_ALTURA&&bola_pos_y+BOLA_TAMANHO>= bloquinho2_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>=bloquinho2_pos_x)
                    {if(bola_pos_x<=bloquinho2_pos_x + BLOCO_LARGURA)
                      {bola_vy = -bola_vy;bloquinho2_pos_x=-200;numbloc--;
                      al_play_sample(musbloc, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}

            if(bola_pos_y <= bloquinho3_pos_y + BLOCO_ALTURA&&bola_pos_y+BOLA_TAMANHO>= bloquinho3_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>=bloquinho3_pos_x)
                    {if(bola_pos_x<=bloquinho3_pos_x + BLOCO_LARGURA)
                       {bola_vy = -bola_vy*1.1;bloquinho3_pos_x=-200;numbloc--;
                       al_play_sample(musbloc, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}

            if(bola_pos_y <= bloquinho4_pos_y + BLOCO_ALTURA&&bola_pos_y+BOLA_TAMANHO>= bloquinho4_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>=bloquinho4_pos_x)
                    {if(bola_pos_x<=bloquinho4_pos_x + BLOCO_LARGURA)
                       {bola_vy = -bola_vy;bloquinho4_pos_x=-200;numbloc--;
                       al_play_sample(musbloc, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}

            if(bola_pos_y <= bloquinho5_pos_y + BLOCO_ALTURA&&bola_pos_y+BOLA_TAMANHO>= bloquinho5_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>=bloquinho5_pos_x)
                    {if(bola_pos_x<=bloquinho5_pos_x + BLOCO_LARGURA)
                      {bola_vy = -bola_vy;bloquinho5_pos_x=-200;numbloc--;
                      al_play_sample(musbloc, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}

            if(bola_pos_y <= bloquinho6_pos_y + BLOCO_ALTURA&&bola_pos_y+BOLA_TAMANHO>= bloquinho6_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>=bloquinho6_pos_x)
                    {if(bola_pos_x<=bloquinho6_pos_x + BLOCO_LARGURA)
                       {bola_vy = -bola_vy;bloquinho6_pos_x=-200;numbloc--;
                       al_play_sample(musbloc, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}

            if(bola_pos_y <= bloquinho7_pos_y + BLOCO_ALTURA&&bola_pos_y+BOLA_TAMANHO>= bloquinho7_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>=bloquinho7_pos_x)
                    {if(bola_pos_x<=bloquinho7_pos_x + BLOCO_LARGURA)
                       {bola_vy = -bola_vy*1.1;bloquinho7_pos_x=-200;numbloc--;
                       al_play_sample(musbloc, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}

            if(bola_pos_y <= bloquinho8_pos_y + BLOCO_ALTURA&&bola_pos_y+BOLA_TAMANHO>= bloquinho8_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>=bloquinho8_pos_x)
                    {if(bola_pos_x<=bloquinho8_pos_x + BLOCO_LARGURA)
                       {bola_vy = -bola_vy;bloquinho8_pos_x=-200;numbloc--;
                       al_play_sample(musbloc, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}

            if(bola_pos_y <= bloquinho9_pos_y + BLOCO_ALTURA&&bola_pos_y+BOLA_TAMANHO>= bloquinho9_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>=bloquinho9_pos_x)
                    {if(bola_pos_x<=bloquinho9_pos_x + BLOCO_LARGURA)
                       {bola_vy = -bola_vy*1.2;bloquinho9_pos_x=-200;numbloc--;
                       al_play_sample(musbloc, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}

            if(bola_pos_y <= bloquinho10_pos_y + BLOCO_ALTURA&&bola_pos_y+BOLA_TAMANHO>= bloquinho10_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>=bloquinho10_pos_x)
                    {if(bola_pos_x<=bloquinho10_pos_x + BLOCO_LARGURA)
                       {bola_vy = -bola_vy*1.1;bloquinho10_pos_x=-200;numbloc--;
                       al_play_sample(musbloc, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}

             if(bola_pos_y <= bloquinho11_pos_y + BLOCO_ALTURA&&bola_pos_y+BOLA_TAMANHO>= bloquinho11_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>=bloquinho11_pos_x)
                    {if(bola_pos_x<=bloquinho11_pos_x + BLOCO_LARGURA)
                      {bola_vy = -bola_vy;bloquinho11_pos_x=-200;numbloc--;
                      al_play_sample(musbloc, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}

             if(bola_pos_y <= bloquinho12_pos_y + BLOCO_ALTURA&&bola_pos_y+BOLA_TAMANHO>= bloquinho12_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>=bloquinho12_pos_x)
                    {if(bola_pos_x<=bloquinho12_pos_x + BLOCO_LARGURA)
                      {bola_vy = -bola_vy;bloquinho12_pos_x=-200;numbloc--;
                      al_play_sample(musbloc, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}

             if(bola_pos_y <= bloquinho13_pos_y + BLOCO_ALTURA&&bola_pos_y+BOLA_TAMANHO>= bloquinho13_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>=bloquinho13_pos_x)
                    {if(bola_pos_x<=bloquinho13_pos_x + BLOCO_LARGURA)
                       {bola_vy = -bola_vy;bloquinho13_pos_x=-200;numbloc--;
                       al_play_sample(musbloc, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}

             if(bola_pos_y <= bloquinho14_pos_y + BLOCO_ALTURA&&bola_pos_y+BOLA_TAMANHO>= bloquinho14_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>=bloquinho14_pos_x)
                    {if(bola_pos_x<=bloquinho14_pos_x + BLOCO_LARGURA)
                       {bola_vy = -bola_vy;bloquinho14_pos_x=-200;numbloc--;
                       al_play_sample(musbloc, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}

            if(bola_pos_y <= bloquinho15_pos_y + BLOCO_ALTURA&&bola_pos_y+BOLA_TAMANHO>= bloquinho15_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>=bloquinho15_pos_x)
                    {if(bola_pos_x<=bloquinho15_pos_x + BLOCO_LARGURA)
                      {bola_vy = -bola_vy;bloquinho15_pos_x=-200;numbloc--;
                      al_play_sample(musbloc, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}

             if(bola_pos_y <= bloquinho16_pos_y + BLOCO_ALTURA&&bola_pos_y+BOLA_TAMANHO>= bloquinho16_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>=bloquinho16_pos_x)
                    {if(bola_pos_x<=bloquinho16_pos_x + BLOCO_LARGURA)
                       {bola_vy = -bola_vy;bloquinho16_pos_x=-200;numbloc--;
                       al_play_sample(musbloc, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}

            if(bola_pos_y <= bloquinho17_pos_y + BLOCO_ALTURA&&bola_pos_y+BOLA_TAMANHO>= bloquinho17_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>=bloquinho17_pos_x)
                    {if(bola_pos_x<=bloquinho17_pos_x + BLOCO_LARGURA)
                       {bola_vy = -bola_vy;bloquinho17_pos_x=-200;numbloc--;
                       al_play_sample(musbloc, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}

            if(bola_pos_y <= bloquinho18_pos_y + BLOCO_ALTURA&&bola_pos_y+BOLA_TAMANHO>= bloquinho18_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>=bloquinho18_pos_x)
                    {if(bola_pos_x<=bloquinho18_pos_x + BLOCO_LARGURA)
                       {bola_vy = -bola_vy;bloquinho18_pos_x=-200;numbloc--;
                       al_play_sample(musbloc, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}

            if(bola_pos_y <= bloquinho19_pos_y + BLOCO_ALTURA&&bola_pos_y+BOLA_TAMANHO>= bloquinho19_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>=bloquinho19_pos_x)
                    {if(bola_pos_x<=bloquinho19_pos_x + BLOCO_LARGURA)
                       {bola_vy = -bola_vy*1.1;bloquinho19_pos_x=-200;numbloc--;
                       al_play_sample(musbloc, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}
                       }


            if(cont==0){

                bola  =  al_load_bitmap("imagens/bola1.png");

            if(bola_pos_y <= bloquinho_pos_y + BLOCO_ALTURA&&bola_pos_y+BOLA_TAMANHO>= bloquinho_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>bloquinho_pos_x)
                    {if(bola_pos_x<bloquinho_pos_x + 70)
                       {bola_vy = -bola_vy*1.2;Sleep(10);cont=1;
                       al_play_sample(musblocx, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}

            if(bola_pos_y <= bloquinho1_pos_y + BLOCO_ALTURA&&bola_pos_y+BOLA_TAMANHO>= bloquinho1_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>bloquinho1_pos_x)
                    {if(bola_pos_x<bloquinho1_pos_x + 70)
                      {bola_vy = -bola_vy;Sleep(10);cont=1;
                      al_play_sample(musblocx, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}

            if(bola_pos_y <= bloquinho2_pos_y + BLOCO_ALTURA&&bola_pos_y+BOLA_TAMANHO>= bloquinho2_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>bloquinho2_pos_x)
                    {if(bola_pos_x<bloquinho2_pos_x + 70)
                      {bola_vy = -bola_vy;Sleep(10);cont=1;
                      al_play_sample(musblocx, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}

            if(bola_pos_y <= bloquinho3_pos_y + BLOCO_ALTURA&&bola_pos_y+BOLA_TAMANHO>= bloquinho3_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>bloquinho3_pos_x)
                    {if(bola_pos_x<bloquinho3_pos_x + 70)
                       {bola_vy = -bola_vy*1.1;Sleep(10);cont=1;
                       al_play_sample(musblocx, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}

            if(bola_pos_y <= bloquinho4_pos_y + BLOCO_ALTURA&&bola_pos_y+BOLA_TAMANHO>= bloquinho4_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>bloquinho4_pos_x)
                    {if(bola_pos_x<bloquinho4_pos_x + 70)
                       {bola_vy = -bola_vy;Sleep(10);cont=1;
                       al_play_sample(musblocx, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}

            if(bola_pos_y <= bloquinho5_pos_y + BLOCO_ALTURA&&bola_pos_y+BOLA_TAMANHO>= bloquinho5_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>bloquinho5_pos_x)
                    {if(bola_pos_x<bloquinho5_pos_x + 70)
                      {bola_vy = -bola_vy;Sleep(10);cont=1;
                      al_play_sample(musblocx, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}

            if(bola_pos_y <= bloquinho6_pos_y + BLOCO_ALTURA&&bola_pos_y+BOLA_TAMANHO>= bloquinho6_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>bloquinho6_pos_x)
                    {if(bola_pos_x<bloquinho6_pos_x + 70)
                       {bola_vy = -bola_vy;Sleep(10);cont=1;
                       al_play_sample(musblocx, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}

            if(bola_pos_y <= bloquinho7_pos_y + BLOCO_ALTURA&&bola_pos_y+BOLA_TAMANHO>= bloquinho7_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>bloquinho7_pos_x)
                    {if(bola_pos_x<bloquinho7_pos_x + 70)
                       {bola_vy = -bola_vy*1.1;Sleep(10);cont=1;
                       al_play_sample(musblocx, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}

            if(bola_pos_y <= bloquinho8_pos_y + BLOCO_ALTURA&&bola_pos_y+BOLA_TAMANHO>= bloquinho8_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>bloquinho8_pos_x)
                    {if(bola_pos_x<bloquinho8_pos_x + 70)
                       {bola_vy = -bola_vy;Sleep(10);cont=1;
                       al_play_sample(musblocx, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}

            if(bola_pos_y <= bloquinho9_pos_y + BLOCO_ALTURA&&bola_pos_y+BOLA_TAMANHO>= bloquinho9_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>bloquinho9_pos_x)
                    {if(bola_pos_x<=bloquinho9_pos_x + BLOCO_LARGURA)
                       {bola_vy = -bola_vy*1.2;Sleep(10);cont=1;
                       al_play_sample(musblocx, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}

            if(bola_pos_y <= bloquinho10_pos_y + BLOCO_ALTURA&&bola_pos_y+BOLA_TAMANHO>= bloquinho10_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>=bloquinho10_pos_x)
                    {if(bola_pos_x<bloquinho10_pos_x + 70)
                       {bola_vy = -bola_vy*1.1;Sleep(10);cont=1;
                       al_play_sample(musblocx, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}

             if(bola_pos_y <= bloquinho11_pos_y + BLOCO_ALTURA&&bola_pos_y+BOLA_TAMANHO>= bloquinho11_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>bloquinho11_pos_x)
                    {if(bola_pos_x<bloquinho11_pos_x + 70)
                      {bola_vy = -bola_vy;Sleep(10);cont=1;
                      al_play_sample(musblocx, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}

             if(bola_pos_y <= bloquinho12_pos_y + BLOCO_ALTURA&&bola_pos_y+BOLA_TAMANHO>= bloquinho12_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>bloquinho12_pos_x)
                    {if(bola_pos_x<bloquinho12_pos_x + 70)
                      {bola_vy = -bola_vy;Sleep(10);cont=1;
                      al_play_sample(musblocx, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}

             if(bola_pos_y <= bloquinho13_pos_y + BLOCO_ALTURA&&bola_pos_y+BOLA_TAMANHO>= bloquinho13_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>bloquinho13_pos_x)
                    {if(bola_pos_x<bloquinho13_pos_x + 70)
                       {bola_vy = -bola_vy;Sleep(10);cont=1;
                       al_play_sample(musblocx, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}

             if(bola_pos_y <= bloquinho14_pos_y + BLOCO_ALTURA&&bola_pos_y+BOLA_TAMANHO>= bloquinho14_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>bloquinho14_pos_x)
                    {if(bola_pos_x<bloquinho14_pos_x + 70)
                       {bola_vy = -bola_vy;Sleep(10);cont=1;
                       al_play_sample(musblocx, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}

            if(bola_pos_y <= bloquinho15_pos_y + BLOCO_ALTURA&&bola_pos_y+BOLA_TAMANHO>= bloquinho15_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>bloquinho15_pos_x)
                    {if(bola_pos_x<bloquinho15_pos_x + 70)
                      {bola_vy = -bola_vy;Sleep(10);cont=1;
                      al_play_sample(musblocx, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}

             if(bola_pos_y <= bloquinho16_pos_y + BLOCO_ALTURA&&bola_pos_y+BOLA_TAMANHO>= bloquinho16_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>bloquinho16_pos_x)
                    {if(bola_pos_x<bloquinho16_pos_x + 70)
                       {bola_vy = -bola_vy;Sleep(10);cont=1;
                       al_play_sample(musblocx, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}

            if(bola_pos_y <= bloquinho17_pos_y + BLOCO_ALTURA&&bola_pos_y+BOLA_TAMANHO>= bloquinho17_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>bloquinho17_pos_x)
                    {if(bola_pos_x<bloquinho17_pos_x + 70)
                       {bola_vy = -bola_vy;Sleep(10);cont=1;
                       al_play_sample(musblocx, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}

            if(bola_pos_y <= bloquinho18_pos_y + BLOCO_ALTURA&&bola_pos_y+BOLA_TAMANHO>= bloquinho18_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>bloquinho18_pos_x)
                    {if(bola_pos_x<bloquinho18_pos_x + 70)
                       {bola_vy = -bola_vy;Sleep(10);cont=1;
                       al_play_sample(musblocx, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}

            if(bola_pos_y <= bloquinho19_pos_y + BLOCO_ALTURA&&bola_pos_y+BOLA_TAMANHO>= bloquinho19_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>bloquinho19_pos_x)
                    {if(bola_pos_x<=bloquinho19_pos_x + BLOCO_LARGURA)
                       {bola_vy = -bola_vy*1.1;Sleep(10);cont=1;
                       al_play_sample(musblocx, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}
                        }


if(cont==1){
            if(bola_pos_y < bloquinhox1_pos_y + 20&&bola_pos_y+BOLA_TAMANHO> bloquinhox1_pos_y)
             {if(bola_pos_y <= bloquinhox1_pos_y + 20||bola_pos_y+BOLA_TAMANHO>= bloquinhox1_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>=bloquinhox1_pos_x)
                    {if(bola_pos_x<=bloquinhox1_pos_x + 80)
                      {bola_vy = -bola_vy;cont=0;
                      al_play_sample(musblocx, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}}

            if(bola_pos_y < bloquinhox2_pos_y + 20&&bola_pos_y+BOLA_TAMANHO> bloquinhox2_pos_y)
              {if(bola_pos_y <= bloquinhox2_pos_y + 20||bola_pos_y+BOLA_TAMANHO>= bloquinhox2_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>=bloquinhox2_pos_x)
                    {if(bola_pos_x<=bloquinhox2_pos_x + 80)
                      {bola_vy = -bola_vy;cont=0;
                      al_play_sample(musblocx, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}}

            if(bola_pos_y < bloquinhox3_pos_y + 20&&bola_pos_y+BOLA_TAMANHO> bloquinhox3_pos_y)
             {if(bola_pos_y <= bloquinhox3_pos_y + 20||bola_pos_y+BOLA_TAMANHO>= bloquinhox3_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>=bloquinhox3_pos_x)
                    {if(bola_pos_x<=bloquinhox3_pos_x + 80)
                       {bola_vy = -bola_vy*1.1;cont=0;
                       al_play_sample(musblocx, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}}

            if(bola_pos_y < bloquinhox4_pos_y + 20&&bola_pos_y+BOLA_TAMANHO> bloquinhox4_pos_y)
              {if(bola_pos_y <= bloquinhox4_pos_y + 20||bola_pos_y+BOLA_TAMANHO>= bloquinhox4_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>=bloquinhox4_pos_x)
                    {if(bola_pos_x<=bloquinhox4_pos_x + 80)
                       {bola_vy = -bola_vy;cont=0;
                       al_play_sample(musblocx, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}}

            if(bola_pos_y < bloquinhox5_pos_y + 20&&bola_pos_y+BOLA_TAMANHO> bloquinhox5_pos_y)
              {if(bola_pos_y <= bloquinhox5_pos_y + 20||bola_pos_y+BOLA_TAMANHO>= bloquinhox5_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>=bloquinhox5_pos_x)
                    {if(bola_pos_x<=bloquinhox5_pos_x + 80)
                      {bola_vy = -bola_vy;cont=0;
                      al_play_sample(musblocx, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}}

            if(bola_pos_y < bloquinhox6_pos_y + 20&&bola_pos_y+BOLA_TAMANHO> bloquinhox6_pos_y)
              {if(bola_pos_y <= bloquinhox6_pos_y + 20||bola_pos_y+BOLA_TAMANHO>= bloquinhox6_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>=bloquinhox6_pos_x)
                    {if(bola_pos_x<=bloquinhox6_pos_x + 60)
                       {bola_vy = -bola_vy;cont=0;
                       al_play_sample(musblocx, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}}

            if(bola_pos_y < bloquinhox7_pos_y + 20&&bola_pos_y+BOLA_TAMANHO> bloquinhox7_pos_y)
             {if(bola_pos_y <= bloquinhox7_pos_y + 20||bola_pos_y+BOLA_TAMANHO>= bloquinhox7_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>=bloquinhox7_pos_x)
                    {if(bola_pos_x<=bloquinhox7_pos_x + 80)
                       {bola_vy = -bola_vy*1.1;cont=0;
                       al_play_sample(musblocx, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}}

            if(bola_pos_y < bloquinhox8_pos_y + 20&&bola_pos_y+BOLA_TAMANHO> bloquinhox8_pos_y)
              {if(bola_pos_y <= bloquinhox8_pos_y + 20||bola_pos_y+BOLA_TAMANHO>= bloquinhox8_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>=bloquinhox8_pos_x)
                    {if(bola_pos_x<=bloquinhox8_pos_x + 80)
                       {bola_vy = -bola_vy;cont=0;
                       al_play_sample(musblocx, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}}

            if(bola_pos_y < bloquinhox9_pos_y + 20&&bola_pos_y+BOLA_TAMANHO> bloquinhox9_pos_y)
              {if(bola_pos_y <= bloquinhox9_pos_y + 20||bola_pos_y+BOLA_TAMANHO>= bloquinhox9_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>=bloquinhox9_pos_x+20)
                    {if(bola_pos_x<=bloquinhox9_pos_x + 80)
                       {bola_vy = -bola_vy*1.2;cont=0;
                       al_play_sample(musblocx, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}}

            if(bola_pos_y < bloquinhox10_pos_y + 20&&bola_pos_y+BOLA_TAMANHO> bloquinhox10_pos_y)
              {if(bola_pos_y <= bloquinhox10_pos_y + 20||bola_pos_y+BOLA_TAMANHO>= bloquinhox10_pos_y)
                {if(bola_pos_x+BOLA_TAMANHO>=bloquinhox10_pos_x)
                    {if(bola_pos_x<=bloquinhox10_pos_x + 80)
                       {bola_vy = -bola_vy*1.1;cont=0;
                       al_play_sample(musblocx, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}}
           }


             if(bola_pos_x<=rebatedorBase_pos_x+REBATEDOR_LARGURA)
             {if(bola_pos_x>rebatedorBase_pos_x+60)
             {if(bola_pos_x + BOLA_TAMANHO >= rebatedorBase_pos_x)
              {if(bola_pos_y+BOLA_TAMANHO > rebatedorBase_pos_y)
                {bola_vy = -bola_vy*1.1;cont=1;
                al_play_sample(musrebt, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}}

                 if(bola_pos_x<=rebatedorBase_pos_x+REBATEDOR_LARGURA)
                {if(bola_pos_x<rebatedorBase_pos_x+20)
            {if(bola_pos_x + BOLA_TAMANHO >= rebatedorBase_pos_x)
              {if(bola_pos_y+BOLA_TAMANHO > rebatedorBase_pos_y)
                {bola_vy = -bola_vy*1.1;cont=1;
                al_play_sample(musrebt, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}}

                 if(bola_pos_x<=rebatedorBase_pos_x+REBATEDOR_LARGURA)
                {if(bola_pos_x>=rebatedorBase_pos_x+20)
                {if(bola_pos_x<=rebatedorBase_pos_x+60)
            {if(bola_pos_x + BOLA_TAMANHO >= rebatedorBase_pos_x)
              {if(bola_pos_y+BOLA_TAMANHO > rebatedorBase_pos_y)
                {bola_vy = -bola_vy;cont=1;
                al_play_sample(musrebt, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);}}}}}


            if(bola_vy>=8)bola_vy-=2;
            if(bola_vx>=8)bola_vx-=2;

            if(rebatedorBase_pos_x<=0)rebatedorBase_pos_x=0;
            if(rebatedorBase_pos_x>=920)rebatedorBase_pos_x=920;


            if(bloquinhox1_pos_x<=0||bloquinhox1_pos_x>=920)bloquinhox1_vx=-bloquinhox1_vx;
            if(bloquinhox2_pos_x<=0||bloquinhox2_pos_x>=920)bloquinhox2_vx=-bloquinhox2_vx;
            if(bloquinhox3_pos_x<=0||bloquinhox3_pos_x>=920)bloquinhox3_vx=-bloquinhox3_vx;


            if(bola_vx!=0)
            {
            bloquinhox1_pos_x += bloquinhox1_vx;
            bloquinhox2_pos_x += bloquinhox2_vx;
            bloquinhox3_pos_x += bloquinhox3_vx;
            }

            bola_pos_x              += bola_vx;
            bola_pos_y              += bola_vy;
            rebatedorBase_pos_x     += rebatedorBase_vx;
            redraw = true;
        }
        else
            if(ev.type == ALLEGRO_EVENT_KEY_CHAR&&bola_vy!=0)
            {
            switch(ev.keyboard.keycode)
            {
            case ALLEGRO_KEY_LEFT:
                rebatedorBase_vx=-7;
                break;
            case ALLEGRO_KEY_RIGHT:
                rebatedorBase_vx=7;
                break;
            }
            }
     if(ev.type == ALLEGRO_EVENT_KEY_CHAR)
            {
            switch(ev.keyboard.keycode)
            {
            case ALLEGRO_KEY_ESCAPE:
                return 0;
                break;
            }
        }

        else if(ev.type == ALLEGRO_EVENT_KEY_UP)
        {
            switch(ev.keyboard.keycode)
            {
            case ALLEGRO_KEY_LEFT:

            case ALLEGRO_KEY_RIGHT:
                rebatedorBase_vx=0;
                break;
            }
        }

        else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            break;
        }

        if(redraw && al_is_event_queue_empty(event_queue))

        {
            redraw = false;
            al_clear_to_color(al_map_rgb(0,255,0));

            al_draw_bitmap(background,backgroundpx, 0, 0);
            al_draw_bitmap(background1,backgroundpx1, 0, 0);
            al_draw_bitmap(background2, 0,backgroundpx2, 0);
            al_draw_bitmap(background3, 0,backgroundpx3, 0);
            al_draw_bitmap(background4, 0,backgroundpx4, 0);
            al_draw_bitmap(life1, life1px, life1py, 0);
            al_draw_bitmap(life2, life2px, life2py, 0);
            al_draw_bitmap(life3, life3px, life3py, 0);



            al_draw_bitmap(bloquinho,bloquinho_pos_x, bloquinho_pos_y, 0);
            al_draw_bitmap(bloquinho1,bloquinho1_pos_x, bloquinho1_pos_y, 0);
            al_draw_bitmap(bloquinho2,bloquinho2_pos_x, bloquinho2_pos_y, 0);
            al_draw_bitmap(bloquinho3,bloquinho3_pos_x, bloquinho3_pos_y, 0);
            al_draw_bitmap(bloquinho4,bloquinho4_pos_x, bloquinho4_pos_y, 0);
            al_draw_bitmap(bloquinho5,bloquinho5_pos_x, bloquinho5_pos_y, 0);
            al_draw_bitmap(bloquinho6,bloquinho6_pos_x, bloquinho6_pos_y, 0);
            al_draw_bitmap(bloquinho7,bloquinho7_pos_x, bloquinho7_pos_y, 0);
            al_draw_bitmap(bloquinho8,bloquinho8_pos_x, bloquinho8_pos_y, 0);
            al_draw_bitmap(bloquinho9,bloquinho9_pos_x, bloquinho9_pos_y, 0);
            al_draw_bitmap(bloquinho10,bloquinho10_pos_x, bloquinho10_pos_y, 0);
            al_draw_bitmap(bloquinho11,bloquinho11_pos_x, bloquinho11_pos_y, 0);
            al_draw_bitmap(bloquinho12,bloquinho12_pos_x, bloquinho12_pos_y, 0);
            al_draw_bitmap(bloquinho13,bloquinho13_pos_x, bloquinho13_pos_y, 0);
            al_draw_bitmap(bloquinho14,bloquinho14_pos_x, bloquinho14_pos_y, 0);
            al_draw_bitmap(bloquinho15,bloquinho15_pos_x, bloquinho15_pos_y, 0);
            al_draw_bitmap(bloquinho16,bloquinho16_pos_x, bloquinho16_pos_y, 0);
            al_draw_bitmap(bloquinho17,bloquinho17_pos_x, bloquinho17_pos_y, 0);
            al_draw_bitmap(bloquinho18,bloquinho18_pos_x, bloquinho18_pos_y, 0);
            al_draw_bitmap(bloquinho19,bloquinho19_pos_x, bloquinho19_pos_y, 0);

            al_draw_bitmap(bloquinhox1,bloquinhox1_pos_x, bloquinhox1_pos_y, 0);
            al_draw_bitmap(bloquinhox2,bloquinhox2_pos_x, bloquinhox2_pos_y, 0);
            al_draw_bitmap(bloquinhox3,bloquinhox3_pos_x, bloquinhox3_pos_y, 0);
            al_draw_bitmap(bloquinhox4,bloquinhox4_pos_x, bloquinhox4_pos_y, 0);
            al_draw_bitmap(bloquinhox5,bloquinhox5_pos_x, bloquinhox5_pos_y, 0);
            al_draw_bitmap(bloquinhox6,bloquinhox6_pos_x, bloquinhox6_pos_y, 0);
            al_draw_bitmap(bloquinhox7,bloquinhox7_pos_x, bloquinhox7_pos_y, 0);
            al_draw_bitmap(bloquinhox8,bloquinhox8_pos_x, bloquinhox8_pos_y, 0);
            al_draw_bitmap(bloquinhox9,bloquinhox9_pos_x, bloquinhox9_pos_y, 0);
            al_draw_bitmap(bloquinhox10,bloquinhox10_pos_x, bloquinhox10_pos_y, 0);

            al_draw_bitmap(rebatedorBase,rebatedorBase_pos_x,rebatedorBase_pos_y , 0);

            al_draw_bitmap(bola, bola_pos_x, bola_pos_y, 0);

            al_draw_bitmap(nivel, nivelpx, nivelpy, 0);
            al_draw_bitmap(nivel1, nivelpx1, nivelpy1, 0);
            al_draw_bitmap(nivel2, nivelpx2, nivelpy2, 0);
            al_draw_bitmap(nivel3, nivelpx3, nivelpy3, 0);

            al_draw_bitmap(jogar, jogarpx, jogarpy, 0);
            al_draw_bitmap(over, overpx, overpy, 0);
            al_draw_bitmap(fim, fimpx, fimpy, 0);

            al_flip_display();
        }
    }

    al_destroy_bitmap(bola);

    al_destroy_bitmap(bloquinho);
    al_destroy_bitmap(bloquinho1);
    al_destroy_bitmap(bloquinho2);
    al_destroy_bitmap(bloquinho3);
    al_destroy_bitmap(bloquinho4);
    al_destroy_bitmap(bloquinho5);
    al_destroy_bitmap(bloquinho6);
    al_destroy_bitmap(bloquinho7);
    al_destroy_bitmap(bloquinho8);
    al_destroy_bitmap(bloquinho9);
    al_destroy_bitmap(bloquinho10);
    al_destroy_bitmap(bloquinho11);
    al_destroy_bitmap(bloquinho12);
    al_destroy_bitmap(bloquinho13);
    al_destroy_bitmap(bloquinho14);
    al_destroy_bitmap(bloquinho15);
    al_destroy_bitmap(bloquinho16);
    al_destroy_bitmap(bloquinho17);
    al_destroy_bitmap(bloquinho18);
    al_destroy_bitmap(bloquinho19);

    al_destroy_bitmap(bloquinhox1);
    al_destroy_bitmap(bloquinhox2);
    al_destroy_bitmap(bloquinhox3);
    al_destroy_bitmap(bloquinhox4);
    al_destroy_bitmap(bloquinhox5);
    al_destroy_bitmap(bloquinhox6);
    al_destroy_bitmap(bloquinhox7);
    al_destroy_bitmap(bloquinhox8);
    al_destroy_bitmap(bloquinhox9);

    al_destroy_bitmap(rebatedorBase);

    al_destroy_timer(timer);

    al_destroy_display(display);

    al_destroy_event_queue(event_queue);

    return 0;
}


bool audio()
{
    if (!al_install_audio())
    {fprintf(stderr, "Falha ao inicializar áudio.\n");
        return false;
    }
    if (!al_init_acodec_addon())
    {fprintf(stderr, "Falha ao inicializar codecs de áudio.\n");
        return false;
    }
    if (!al_reserve_samples(1))
    {fprintf(stderr, "Falha ao alocar canais de áudio.\n");
        return false;
    }
    sample = al_load_sample("audio/win.ogg");
    if (!sample)
    {fprintf(stderr, "Falha ao carregar sample.\n");
        return false;
    }
    musica = al_load_audio_stream("audio/mus.ogg", 4, 1024);
    if (!musica)
    {fprintf(stderr, "Falha ao carregar audio.\n");
        al_destroy_sample(sample);
        return false;
    }
    muswin = al_load_audio_stream("audio/win.ogg", 4, 1024);
    if (!muswin)
    {fprintf(stderr, "Falha ao carregar audio.\n");
        al_destroy_sample(sample);
        return false;
    }
    muswinn1 = al_load_audio_stream("audio/winn1.ogg", 4, 1024);
    if (!muswinn1)
    {fprintf(stderr, "Falha ao carregar audio.\n");
        al_destroy_sample(sample);
        return false;
    }
    muswinn2 = al_load_audio_stream("audio/winn2.ogg", 4, 1024);
    if (!muswinn2)
    {fprintf(stderr, "Falha ao carregar audio.\n");
        al_destroy_sample(sample);
        return false;
    }
    muswinn3 = al_load_audio_stream("audio/winn3.ogg", 4, 1024);
    if (!muswinn3)
    {fprintf(stderr, "Falha ao carregar audio.\n");
        al_destroy_sample(sample);
        return false;
    }
    muswin1 = al_load_audio_stream("audio/win1.ogg", 4, 1024);
    if (!muswin1)
    {fprintf(stderr, "Falha ao carregar audio.\n");
        al_destroy_sample(sample);
        return false;
    }
    musover = al_load_audio_stream("audio/over.ogg", 4, 1024);
    if (!musover)
    {fprintf(stderr, "Falha ao carregar audio.\n");
        al_destroy_sample(sample);
        return false;
    }
   musrebt = al_load_sample("audio/rebt.ogg");
    if (!musrebt)
    {fprintf(stderr, "Falha ao carregar sample.\n");
        return false;
    }
    musbloc = al_load_sample("audio/bloc.ogg");
    if (!musbloc)
    {fprintf(stderr, "Falha ao carregar sample.\n");
        return false;
    }
    musblocx = al_load_sample("audio/blocx.ogg");
    if (!musblocx)
    {fprintf(stderr, "Falha ao carregar sample.\n");
        return false;
    }
    return true;
}
