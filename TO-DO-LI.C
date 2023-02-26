 #include<graphics.h>
 #include<stdio.h>
 #include<conio.h>
 #include<process.h>
 #include<stdlib.h>
 #include<dos.h>
 void createList();
 void readList();
 //void clearScreen();
 void main()
 {
     //	FILE  *fp;
	int font = 0;
	int f = 0;
	int choice,i;
	char tasks[30];
	char continueCreateProcess;
	char optionThreeExit;
	int load =180;
	int load_width = 120;
	int gdriver = DETECT, gmode;
	initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
	START:
	setbkcolor(9);
	setcolor(10);
	settextstyle(font,HORIZ_DIR,3);
	outtextxy(230,20+20,"TO-DO-LIST");
	outtextxy(220,40+30,"-----------");
	setcolor(4);
	settextstyle(f,HORIZ_DIR,3);
	outtextxy(120,80+60,"MENU>");
	settextstyle(8,HORIZ_DIR,1);
	outtextxy(120,80+100,"* 1 Make a List");
	outtextxy(120,80+130,"* 2 Read a List");
	outtextxy(120,80+160,"* 3 Exit");
	settextstyle(7,HORIZ_DIR,2);
	outtextxy(120,80+230,"Select your option =>");
	scanf("%d",&choice);
	setcolor(9);
	setcolor(6);
	settextstyle(7,HORIZ_DIR,1);
	if(choice == 1)
	{
	outtextxy(360,80+230,"You pressed (1)");
       /*	for(i=0 ;i<load;i++)
		{
		outtextxy(load_width+i,80+260,">>");
		delay(20);
		}  */
		createList();
		}
	if(choice == 2)
	{
		readList();

	}
	if(choice == 3)
	{
	setcolor(15);
	outtextxy(120,80+300,"Do you want to exit (Y/N)");
	scanf("%c",&optionThreeExit);
	if(optionThreeExit == 'Y' || optionThreeExit == 'y')
		{
			exit(0);
		}
	else{
		goto START;
	}
	}
	getch();

 }


 void clearScreen() {
	clrscr();
 }
 void createList(){
 FILE *fp;
 //char fileName[30]="default.txt";
 int noOfTask;
 char tasks[30];
 int *p;
 int i;
 //clearScreen();
 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
// delay(80);
 setcolor(15);
// outtextxy(50,80+300,"Enter the name by which you want to create your file");
// outtextxy(90,80+330,"See your file name in above left Corner");
 //gets(fileName);
 fp = fopen("default.txt","w");
 {
 if(fp == NULL)
	{
		outtextxy(120,80+300,"Error in file making");
	}
 else{
	outtextxy(120,80+300,"How many task you want to include ? ");
	scanf("%d",&noOfTask);
	p = (int *)malloc(noOfTask *sizeof(int));
	outtextxy(120,80+360,"Enter your tasks ->");
	for(i=0;i<=noOfTask;i++)
	{

	   gets(tasks);
	   fputs("\n",fp);
	   fputs(tasks,fp);
	   fputs("\n",fp);
	}
	fclose(fp);

 }
 }
 }
 void readList(char tasks)
 {
 FILE *fp;
 char results[30];
 int gd = DETECT,left=100,top=200,bottom=200,right=100;
 clrscr();
 rectangle(left,top,right,bottom);
  outtextxy(120,20+20,"Your TO-DO-LIST is =>");
  fp = fopen("default.txt","r");
    if(fp == NULL)
    {
    outtextxy(120,80+300,"Error in file opening");
    }

  while(fgets(results,30,fp)!=NULL)
      {
	puts(results);
      }
      fclose(fp);
 }

