/*
Programa / Obra: The Journey Unseen / A Jornada Não Observada.
Autor:      Fábio R. Nóbrega
Data :      Outubro/2017

  A reprodutibilidade da imagem na era digital se torna um objeto
de estudo para o Artista. Mostrando com esse processo de visualização
da primeira imagem transmitida na World Wide Web através de um cliente
HTTP e um Servidor, como perdemos as características e o controle da imagem
neste meio em rede. A partir dos controles que modificam a posição da imagem
o usuário pode então refletir sobre a nova "Aura" que a imagem ganha dentro
deste novo contexto.

Segundo Perrie Lévy "A Imagem perde sua exterioridade de espetáculo para
abrir-se à imersão. A representação é substituída pela visualização interativa
de um modelo" (Cibercultura)

Agradecimentos especiais;

Floriano Romano
Paulo Roma Cavalcanti
Thiago Henrique Hüpner
Valéria Bastos
Tim Berners-Lee
Equipe Criativa OpenGL 1.0
.*/



#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
float angulo = 0.0f,rotX = 0.0,rotY = 0.0f,rotZ = 1.0f, velocidade = 0.0;
int w,h;

GLuint texid1;


char *load_bmp(char * name){

    FILE *f = fopen(name,"rb");
    if(f == NULL) exit(0);
    int of;
    fseek(f, 10, SEEK_SET);
    fread(&of, sizeof(int), 1, f);
    fseek(f, 4, SEEK_CUR);
    fread(&w, sizeof(int), 1, f);
    fread(&h, sizeof(int), 1, f);

    fseek(f, of, SEEK_SET);

    int by = ((w * 3 + 3)/4) * 4 - (w * 3 % 4);
    char *tmp_m = malloc(sizeof(char) * by * h);
    char *m = malloc(sizeof(char) * w * h * 3);
    fread(tmp_m, sizeof(char) * by * h, 1, f);
    int x,y,i;
    for(y = 0; y < h; y++){
        for(x = 0; x < w; x++){
            for(i = 0; i < 3; i++){
                m[3*(w*y + x) + i] = tmp_m[3*(w*y + x) + (2 - i)];
            }
        }
    }
    free(tmp_m);
    return m;
}


GLuint loadTex(char *c){
        char *wa = load_bmp(c);
        GLuint texid;
        glGenTextures(1, &texid);
        glBindTexture(GL_TEXTURE_2D, texid);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, wa);
        free(wa);
        return texid;
}

void colocaImagem(){
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texid1);

        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        }

void DesenhaNaTela(void)
{


    colocaImagem();

    //glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 5,
              0, 0, 0,
              0, 1, 0);



    glRotatef(angulo, rotX, rotY,rotZ);





    glBegin(GL_QUADS);
           //glColor3f(0.0f,0.0f,1.0f);
          glTexCoord2f(0.0, 1.0); glVertex3f(-1, 1, 0);
          glTexCoord2f(1.0, 1.0); glVertex3f( 1, 1, 0);
          glTexCoord2f(1.0, 0.0); glVertex3f( 1,-1, 0);
          glTexCoord2f(0.0, 0.0); glVertex3f(-1,-1, 0);
           glEnd();

      angulo += velocidade;
      printf(" %3.f Visualizações\n",angulo);
      //printf(" %2.f \n",velocidade );

     glutSwapBuffers();

  }



void Inicializa (void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
      texid1 = loadTex("Textura.bmp");
}

void Controle(unsigned char key, int x, int y){
if(key == 27)exit(0);
if(key == 9){ velocidade += 5,0; }
if(key == ' '){ velocidade = 0,0; }

if((char)key == 13 ){
    if(rotZ == 1.0f){
       rotX = 1.0f;
       rotY = 0.0f;
       rotZ = 0.0f;
     } else if (rotY == 1.0f){
       rotX = 0.0f;
       rotY = 0.0f;
       rotZ = 1.0f;
     }else if(rotX == 1.0f){
       rotX = 0.0f;
       rotY = 1.0f;
       rotZ = 0.0f;
     }

   }

}




void AlteraTamanhoJanela(int w, int h) {

    if (h == 0)
        h = 1;

    float proporcao =  w * 1.0 / h;

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    glViewport(0, 0, w, h);

    gluPerspective(45.0f, proporcao, 0.1f, 100.0f);

    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(620,480);
    glutInitWindowPosition(100,100);
    glutCreateWindow("The Journey Unseen");
    Inicializa();
    glutDisplayFunc(DesenhaNaTela);
    glutIdleFunc(DesenhaNaTela);
    glutReshapeFunc(AlteraTamanhoJanela);
    glutKeyboardFunc(Controle);
    glutMainLoop();
}
