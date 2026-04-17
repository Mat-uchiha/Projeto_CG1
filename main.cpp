//includes necessários para OpenGL e funcionalidades básicas
#include <GL/glut.h>
#include <iostream>
#include <cmath>

// definição de variáveis globais para controle do polígono, fiz sem um vetor de vértices para facilitar a manipulação do número de vértices.
int numVertices = 5;
float espessura = 2.0f;
int modoPreenchido = 1;
float posX = 0.0f, posY = 0.0f;
float corPreenchimento[3] = { 0.0f, 0.0f, 1.0f };
float corBorda[3] = { 1.0f, 0.0f, 0.0f };
//uso de f no final dos números para indicar que são float.

// função para desenhar o polígono, usando GL_POLYGON para preenchimento e GL_LINE_LOOP para a borda. O número de vértices é controlado por uma variável global, e a posição do polígono é ajustada usando as setas do teclado.
void desenharPoligono() {
    float raio = 0.5f; // raio do polígono, pode ser ajustado conforme necessário
    // função que desenha o polígono caso o modo de preenchimento esteja ativado.
    if (modoPreenchido) {
        glColor3fv(corPreenchimento);
        glBegin(GL_POLYGON);
        for (int i = 0; i < numVertices; i++) {
            float angulo = 2.0f * 3.14159f * i / numVertices;
            glVertex2f(posX + raio * cos(angulo), posY + raio * sin(angulo)); // cálculo das coordenadas dos vértices do polígono usando funções trigonométricas.
        }
        glEnd();
    }

    glLineWidth(espessura);
    glColor3fv(corBorda);
    glBegin(GL_LINE_LOOP); //desenha a borda do polígono usando GL_LINE_LOOP, que conecta os vértices em um loop fechado.
    for (int i = 0; i < numVertices; i++) {
        float angulo = 2.0f * 3.14159f * i / numVertices;
        glVertex2f(posX + raio * cos(angulo), posY + raio * sin(angulo));
    }
    glEnd();
}
// função de exibição que limpa a tela e chama a função de desenho do polígono, garantindo que o polígono seja redesenhado sempre que necessário.
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    desenharPoligono();
    glFlush();
}

// função de teclado para controlar o número de vértices, o modo de preenchimento, a espessura da borda e as cores do preenchimento e da borda. A função do que cada tecla faz está descrita no relatório.
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'n': case 'N': numVertices++; break; 
    case 'm': case 'M': if (numVertices > 3) numVertices--; break;
    case 'p': case 'P': modoPreenchido = !modoPreenchido; break;
    case 'e': case 'E': espessura += 1.0f; if (espessura > 10.0f) espessura = 1.0f; break;
    case 'r': case 'R': corPreenchimento[0] += 0.1f; if (corPreenchimento[0] > 1.0f) corPreenchimento[0] = 0.0f; break;
    case 'g': case 'G': corPreenchimento[1] += 0.1f; if (corPreenchimento[1] > 1.0f) corPreenchimento[1] = 0.0f; break;
    case 'b': case 'B': corPreenchimento[2] += 0.1f; if (corPreenchimento[2] > 1.0f) corPreenchimento[2] = 0.0f; break;
    case 'v': case 'V': corBorda[0] += 0.1f; if (corBorda[0] > 1.0f) corBorda[0] = 0.0f; break;
    case 'd': case 'D': corBorda[1] += 0.1f; if (corBorda[1] > 1.0f) corBorda[1] = 0.0f; break;
    case 'a': case 'A': corBorda[2] += 0.1f; if (corBorda[2] > 1.0f) corBorda[2] = 0.0f; break;
    }
    glutPostRedisplay();
}
// função para controlar a posição do polígono usando as setas do teclado.
void specialKeys(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_UP:    posY += 0.05f; break;
    case GLUT_KEY_DOWN:  posY -= 0.05f; break;
    case GLUT_KEY_LEFT:  posX -= 0.05f; break;
    case GLUT_KEY_RIGHT: posX += 0.05f; break;
    }
    glutPostRedisplay();
}
// função principal que inicializa o OpenGL, cria a janela, define as funções de exibição e teclado, e inicia o loop principal do OpenGL.
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Atividade OpenGL - Poligono");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);
    glutMainLoop();
    return 0;
}