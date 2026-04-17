#includes necessários para OpenGL e funcionalidades básicas
from OpenGL.GL import *
from OpenGL.GLUT import *
import math

# definição de variáveis globais para controle do polígono, fiz sem um vetor de vértices para facilitar a manipulação do número de vértices.
numVertices = 5
espessura = 2.0
modoPreenchido = 1
posX = 0.0
posY = 0.0
corPreenchimento = [0.0, 0.0, 1.0]
corBorda = [1.0, 0.0, 0.0]
#uso de f no final dos números para indicar que são float.

# função para desenhar o polígono, usando GL_POLYGON para preenchimento e GL_LINE_LOOP para a borda. O número de vértices é controlado por uma variável global, e a posição do polígono é ajustada usando as setas do teclado.
def desenharPoligono():
    raio = 0.5 # raio do polígono, pode ser ajustado conforme necessário
    # função que desenha o polígono caso o modo de preenchimento esteja ativado.
    if modoPreenchido:
        glColor3fv(corPreenchimento)
        glBegin(GL_POLYGON)
        for i in range(numVertices):
            angulo = 2.0 * 3.14159 * i / numVertices
            glVertex2f(posX + raio * math.cos(angulo), posY + raio * math.sin(angulo)) # cálculo das coordenadas dos vértices do polígono usando funções trigonométricas.
        glEnd()

    glLineWidth(espessura)
    glColor3fv(corBorda)
    glBegin(GL_LINE_LOOP) #desenha a borda do polígono usando GL_LINE_LOOP, que conecta os vértices em um loop fechado.
    for i in range(numVertices):
        angulo = 2.0 * 3.14159 * i / numVertices
        glVertex2f(posX + raio * math.cos(angulo), posY + raio * math.sin(angulo))
    glEnd()

# função de exibição que limpa a tela e chama a função de desenho do polígono, garantindo que o polígono seja redesenhado sempre que necessário.
def display():
    glClear(GL_COLOR_BUFFER_BIT)
    desenharPoligono()
    glFlush()

# função de teclado para controlar o número de vértices, o modo de preenchimento, a espessura da borda e as cores do preenchimento e da borda. A função do que cada tecla faz está descrita no relatório.
def keyboard(key, x, y):
    global numVertices, modoPreenchido, espessura, corPreenchimento, corBorda
    key = key.decode("utf-8")
    if key in ['n', 'N']:
        numVertices += 1
    elif key in ['m', 'M']:
        if numVertices > 3:
            numVertices -= 1
    elif key in ['p', 'P']:
        modoPreenchido = not modoPreenchido
    elif key in ['e', 'E']:
        espessura += 1.0
        if espessura > 10.0:
            espessura = 1.0
    elif key in ['r', 'R']:
        corPreenchimento[0] += 0.1
        if corPreenchimento[0] > 1.0:
            corPreenchimento[0] = 0.0
    elif key in ['g', 'G']:
        corPreenchimento[1] += 0.1
        if corPreenchimento[1] > 1.0:
            corPreenchimento[1] = 0.0
    elif key in ['b', 'B']:
        corPreenchimento[2] += 0.1
        if corPreenchimento[2] > 1.0:
            corPreenchimento[2] = 0.0
    elif key in ['v', 'V']:
        corBorda[0] += 0.1
        if corBorda[0] > 1.0:
            corBorda[0] = 0.0
    elif key in ['d', 'D']:
        corBorda[1] += 0.1
        if corBorda[1] > 1.0:
            corBorda[1] = 0.0
    elif key in ['a', 'A']:
        corBorda[2] += 0.1
        if corBorda[2] > 1.0:
            corBorda[2] = 0.0
    glutPostRedisplay()

# função para controlar a posição do polígono usando as setas do teclado.
def specialKeys(key, x, y):
    global posX, posY
    if key == GLUT_KEY_UP:
        posY += 0.05
    elif key == GLUT_KEY_DOWN:
        posY -= 0.05
    elif key == GLUT_KEY_LEFT:
        posX -= 0.05
    elif key == GLUT_KEY_RIGHT:
        posX += 0.05
    glutPostRedisplay()

# função principal que inicializa o OpenGL, cria a janela, define as funções de exibição e teclado, e inicia o loop principal do OpenGL.
def main():
    glutInit()
    glutInitWindowSize(600, 600)
    glutCreateWindow(b"Atividade OpenGL - Poligono")
    glClearColor(1.0, 1.0, 1.0, 1.0)
    glutDisplayFunc(display)
    glutKeyboardFunc(keyboard)
    glutSpecialFunc(specialKeys)
    glutMainLoop()

if __name__ == "__main__":
    main()

