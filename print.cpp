#include <stdio.h>
#include <string>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

using namespace std;

char arr[200] = {0};
char *state;
void gotoxy(){ COORD pos={0,0}; SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); }
DWORD stime;
DWORD etime;
double tick;
int tmp;
char input[100];
string inputs;
string txt = ".txt";
string wav = ".wav";
string folder = "files\\";

int main(){
	printf("����� �ؽ�Ʈ���ϸ��� �Է��� �ּ���. (Ȯ���� ����)\n");
	scanf("%s", input);
	inputs = input;
	
	system("mode con: lines=40 cols=160");
	FILE *fp = fopen((folder+inputs+txt).c_str(),"r");
	PlaySound((folder+inputs+wav).c_str(), 0, SND_FILENAME | SND_ASYNC );
	
	while(1){
		stime = timeGetTime();
		gotoxy();
		for(int i=0; i<39; i++){
			state = fgets(arr, 200, fp);
			if(state == NULL) goto end;
			printf("%s", arr);
		}
		etime = timeGetTime();
		tick = 32.667-(double)(etime-stime);
		printf("tick : %04.1f", tick);
		Sleep(tick>0?tick:0);
	}
	end:
	puts("���� ��� ����");
	scanf("%d", tmp);
	return 0;
}
