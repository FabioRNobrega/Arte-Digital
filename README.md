The Journey Unssen

 (A Jornada não Observada)

	A reprodutibilidade da imagem na era digital se torna um objeto de estudo para Fábio R. Nóbrega que busca refletir os princípios da gravura clássica neste novo meio . Mostrando com esta obra, um  processo de visualização da primeira imagem transmitida  na World Wide Web  por Tim Berners-Lee. A partir desta primícia o artista cria um programa em linguagem de programação C  rodando bibliotecas do OpenGL 1.0 gerando um sistema de visualização de dados interativos. 
	Segundo o Artista a imagem após ser inserida num meio digital perde-se o controle da sua reprodutibilidade e significado, criando assim um gráfico crescente tendendo ao infinito. Portando nessa obra em particular o observador tem a capacidade de ver  essa perda de significado e um numero de cópias em tempo real, podendo também através de um controle físico “parar o tempo”,  dentro desse mini universo da rede e interagir com a imagem. 
	Dentro desse programa a imagem conforme aumenta o numero de reproduções / visualizações gira em torno de seu eixo formando num primeiro momento uma figura estrelada podendo conforme o usuário for interagindo criar estrelas mas deformadas permitindo uma reflexão  sobre a nova "Aura" que a imagem ganha dentro deste contexto.. Segundo Fábio o objetivo da forma é aludir a própria ideia da visualização das estrelas galáticas, onde segundo ele , o que é observado de uma estrela na verdade é o passado dela, isto é, o caminho histórico que  a luz da mesma passou no tempo para podermos enxergá-la, impedindo-nos de  saber  com exatidão como era seu estado inicial. Teoria esta que se aplica também nos movimentos e ações que a imagem digital ganha, à exemplo memes e edições de imagens como Intagram.
	Segundo Perrie Lévy "A Imagem perde sua exterioridade de espetáculo para abrir-se à imersão. A representação é substituída pela visualização interativa de um modelo" (Cibercultura), fato este, que se aplica de forma prática e interativa na obra The Journey Unseen, sem duvida um data arte que merece um olhar mas apurado e uma analise mas profunda futuramente. 

MODO DE USO: 

COPILANDO: 

É necessário copilar o arquivo.c usando OpenGL 1.0: 
[Usando o Linux (Ubuntu/debian ou semelhante) pelo terminal]

1. Instalar o OpenGL e o GLUT (esse método é para os derivados do Debian): 

  $ sudo apt-get install freeglut3-dev 
 
2- Em seguida copilar o arguivo arte.c? 
 
  $ gcc arte.c -o arte -lglut -lGL -lGLU -lm 
 
3- Para roda o programa sertifiquice que a imagem .bmp esta na mesma pasta que o arquivo.c:
 
   $ ./arte 

CONTROLES: 
 
 TAB - ALMENTA VELOCIDA 
 SPACE - PARA 
 ENTER - MECHE A IMAGEM 
 
 OBS: 
  PARA RETIRAR EFEITO GLITCH ( QUE ATIVA O VISUAL DE ESTRELA) RETIRE O COMENTÁRIO DA LINHA 98: 
  
    //glClear(GL_COLOR_BUFFER_BIT); 
    
    
  PARA USAR JOYTICK MICROSOFT XBOX CONTROLLER  USE O ANTIMICRO E ABRA O ARQUIVO "ARTE.joystick.amgp" COM O MESMO. 
 

