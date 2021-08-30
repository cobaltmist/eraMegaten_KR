/*******************************************/
/*  main.c                                 */
/*    アスレチッククラブ会員管理プログラム */
/*******************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>



/***********************************/
/* 会員管理メイン制御              */
/*   メインルーチン                */
/*                                 */
/*   パラメータ : なし             */
/*   リターン   : なし             */
/***********************************/
int main( void )
{
    char   work[ 255 ];
    char   work2[ 255 ];
    char   work3[ 255 ];
    char   cflag[ 255 ];
    char   com[ 255 ];
    char   kuuhaku[ 255 ];
    char   markm[ 255 ];
    FILE   *fp;
    FILE   *fpw;
    char   *pgyou;  
    char   *gyou; 
    char   *sp;
    char   *sp2;
	int ifc_in[ 20 ] = {0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0};
	int pri;
	int l_pri = 0;
	int i;
	int w;
	int c;
	int kmore;
	int mode;
	int if_in;
	int casen;

	
    printf( "\n ファイル名を入力してください" );
    printf( "\n ? " );
    /* 会員コード入力 */
    work[ 0 ] = '\0';
    scanf( "%s", work );
	
    if( (fp = fopen( work, "r" )) == NULL ) {
        sprintf( work2,"%s.ERB" ,work);
    	if( (fp = fopen( work2, "r" )) == NULL ) {
    	    sprintf( work2,"%s.erb" ,work);
    		if( (fp = fopen( work2, "r" )) == NULL ) {
        		printf( "\n OPEN エラー" );
    			scanf( "%s", work );
    			return 0;
    		}
    	}
    }
	sp = strrchr( work , '.' );
	if( sp != NULL ){
		sprintf( work2,"%s" ,sp);
		if( strcmp(work2,".erb") == 0 || strcmp(work2,".ERB") == 0){
			(*sp) = '\0';
		}
	}
	sprintf( work2,"%s Ver.3.ERB" ,work);
    /* コード・データ対照表ファイル OPEN -> NULL ? */
    if( (fpw = fopen( work2, "w" )) == NULL ) {
        printf( "\n WRITE OPEN エラー" );
    	scanf( "%s", work );
    	fclose(fp);
    	return 0;
    }

    //fgets(work3,255,fp);
	mode = 0;
	while( fgets(work3,255,fp) ) {
		kmore = 0;
		sp = strchr( work3 , ';' );
		if( sp != NULL ){
			sprintf( com,"%s" ,sp);
			(*sp) = '\0';
			c = 1;
		}
		else {
			c = 0;
		}
		if( work3[0] == '@' ){
			if_in = 0;
			
			if(mode > 1 ){
				fputs("$表\示\n",fpw);
				fputs("CALL 口上変数表\示\n",fpw);
			}
			if(mode == 3 ){
				fputs("SIF RESULT < 1\n",fpw);
				fputs("	CALL TRAIN_MESSAGE\n",fpw);
			}
			else if(mode == 4 ){
				fputs("SIF RESULT < 1\n",fpw);
				fputs("	CALL PALAM_MESSAGE_A\n",fpw);
			}
			else if(mode == 5 ){
				fputs("SIF RESULT < 1\n",fpw);
				fputs("	CALL PALAM_MESSAGE_E\n",fpw);
			}
			else if(mode == 6 ){
				fputs("SIF RESULT < 1\n",fpw);
				fputs("	CALL PALAM_MESSAGE_B\n",fpw);
			}
			else if(mode == 7 ){
				fputs("SIF RESULT < 1\n",fpw);
				fputs("	CALL PALAM_MESSAGE_C\n",fpw);
			}
			else if(mode == 8 ){
				fputs("SIF RESULT < 1\n",fpw);
				fputs("	CALL PALAM_MESSAGE_D\n",fpw);
			}
			else if(mode == 10 ){
				fputs("SIF RESULT < 1\n",fpw);
				fputs("	CALL EVENT_MESSAGE\n",fpw);
			}
			mode = 0;
			
			if((sp = strstr(work3,"@EVENTTRAIN_SECOND")) != NULL ){
				fputs(work3,fpw);
				fgets(work3,255,fp);
				mode = 1;
			}
			else if((sp = strstr(work3,"@EVENTTRAIN_")) != NULL ){
				fputs(work3,fpw);
				fputs("CALL 口上変数初期化\n",fpw);
				while( fgets(work3,255,fp) ) {
					if((sp = strstr(work3,";調教開始時")) != NULL )
						break;
					fputs(work3,fpw);
				}
				mode = 2;
			}
			else if((sp = strstr(work3,"@EVENTEND_")) != NULL ){
				fputs(work3,fpw);
				fputs("CALL 口上変数初期化\n",fpw);
				while( fgets(work3,255,fp) ) {
					if((sp = strstr(work3,";調教終了時のセリフ")) != NULL )
						break;
					fputs(work3,fpw);
				}
				mode = 2;
			}
			else if((sp = strstr(work3,"@KOJO_MESSAGE_COM_")) != NULL ){
				fputs(work3,fpw);
				fputs("CALL 口上変数初期化\n",fpw);
				while( fgets(work3,255,fp) ) {
					if((sp = strstr(work3,";コマンド実行時のセリフ")) != NULL )
						break;
					fputs(work3,fpw);
				}
				mode = 3;
			}
			else if((sp = strstr(work3,"@KOJO_MESSAGE_PALAMCNG_A_")) != NULL ){
				fputs(work3,fpw);
				fputs("CALL 口上変数初期化\n",fpw);
				while( fgets(work3,255,fp) ) {
					if((sp = strstr(work3,";調教者の射精時のテキスト")) != NULL )
						break;
					fputs(work3,fpw);
				}
				mode = 4;
			}
			else if((sp = strstr(work3,"@KOJO_MESSAGE_PALAMCNG_E_")) != NULL ){
				fputs(work3,fpw);
				fputs("CALL 口上変数初期化\n",fpw);
				while( fgets(work3,255,fp) ) {
					if((sp = strstr(work3,";触手の射精時")) != NULL )
						break;
					fputs(work3,fpw);
				}
				mode = 5;
			}
			else if((sp = strstr(work3,"@KOJO_MESSAGE_PALAMCNG_B_")) != NULL ){
				fputs(work3,fpw);
				fputs("CALL 口上変数初期化\n",fpw);
				while( fgets(work3,255,fp) ) {
					if((sp = strstr(work3,";奴隷の絶頂時")) != NULL )
						break;
					fputs(work3,fpw);
				}
				mode = 6;
			}
			else if((sp = strstr(work3,"@KOJO_MESSAGE_PALAMCNG_C_")) != NULL ){
				fputs(work3,fpw);
				fputs("CALL 口上変数初期化\n",fpw);
				while( fgets(work3,255,fp) ) {
					if((sp = strstr(work3,";調教後のテキスト")) != NULL )
						break;
					fputs(work3,fpw);
				}
				mode = 7;
			}
			else if((sp = strstr(work3,"@KOJO_MESSAGE_PALAMCNG_D_")) != NULL ){
				fputs(work3,fpw);
				fputs("CALL 口上変数初期化\n",fpw);
				while( fgets(work3,255,fp) ) {
					if((sp = strstr(work3,";パラメータ変化時のテキスト")) != NULL )
						break;
					fputs(work3,fpw);
				}
				mode = 8;
			}
			else if((sp = strstr(work3,"@KOJO_MESSAGE_MARKCNG_")) != NULL ){
				fputs(work3,fpw);
				fputs("CALL 口上変数初期化\n",fpw);
				while( fgets(work3,255,fp) ) {
					if((sp = strstr(work3,"刻印")) != NULL )
						break;
					fputs(work3,fpw);
				}
				mode = 9;
			}
			else if((sp = strstr(work3,"@KOJO_MESSAGE_EVENT_")) != NULL ){
				fputs(work3,fpw);
				fputs("CALL 口上変数初期化\n",fpw);
				while( fgets(work3,255,fp) ) {
					if((sp = strstr(work3,"TFLAG:13")) != NULL )
						break;
					fputs(work3,fpw);
				}
				mode = 10;
			}
			else if((sp = strstr(work3,"@EVENTTURNEND_")) != NULL
			||      (sp = strstr(work3,"@ENEMY_BATTLE_EVENT_")) != NULL
			||      (sp = strstr(work3,"@BATTLE_EVENT_")) != NULL
			||      (sp = strstr(work3,"@BATTLE_MESSAGE_")) != NULL
			||      (sp = strstr(work3,"@セレクト口上説明_")) != NULL
			||      (sp = strstr(work3,"@KOJO_MESSAGE_ENDING_")) != NULL){
				mode = 0;
			}
			else
				mode = 1;
		}
		
		w = strspn(work3, " 	");
		strncpy( kuuhaku,work3,w );
		kuuhaku[ w ] = '\0';
		
		if ( mode > 0){
			i = 0;
			if((sp = strstr(work3,"PRINTFORML")) != NULL ){
				i = 11;
				strcpy( work2,"KSTR:(K++) = " );
				pri = 1;
			}
			else if((sp = strstr(work3,"PRINTFORMW")) != NULL ){
				i = 11;
				strcpy( work2,"WSTR:(K++) = " );
				pri = 1;
			}
			else if((sp = strstr(work3,"PRINTFORM")) != NULL ){
				i = 10;
				strcpy( work2,"NSTR:(K++) = " );
				pri = 1;
			}
			else if((sp = strstr(work3,"PRINTL")) != NULL ){
				i = 7;
				strcpy( work2,"KSTR:(K++) = " );
				pri = 1;
			}
			else if((sp = strstr(work3,"PRINTW")) != NULL ){
				i = 7;
				strcpy( work2,"WSTR:(K++) = " );
				pri = 1;
			}
			else if((sp = strstr(work3,"PRINT")) != NULL ){
				i = 6;
				strcpy( work2,"NSTR:(K++) = " );
				pri = 1;
			}
			else if((sp2 = strstr(work3,"CALL ")) != NULL ){
				i = 5;
				strcpy( work2,"K_CALL:K = " );
				if((sp = strstr(work3,"TRAIN_MESSAGE")) != NULL ||
				   (sp = strstr(work3,"PALAM_MESSAGE_A")) != NULL ||
				   (sp = strstr(work3,"MARK_MESSAGE_")) != NULL ||
				   (sp = strstr(work3,"EVENT_MESSAGE")) != NULL ||
				   (sp = strstr(work3,"PALAM_MESSAGE_")) != NULL ){
					sp = sp2;
				   	if( mode == 9 )
				   		strcpy( markm,(sp + i) );
				}
			}
			else if((sp = strstr(work3,"SETCOLOR ")) != NULL ){
				i = 9;
				strcpy( work2,"KCOLOR:K = " );
				pri = 2;
			}
			else if((sp = strstr(work3,"RESETCOLOR")) != NULL ){
				i = 10;
				strcpy( work2,"KCOLOR:K = GETDEFCOLOR()" );
				pri = 2;
			}
			else {
				pri = 0;
			}
			
			if( sp != NULL){
				//printf("\n 行変換");
				(*sp) = '\0';
				//printf("\n %s",work3);
				//printf("%s",work2);
				//printf("%s",(sp + i));
				//printf("\n %s%s%s",work3,work2,(sp + i));
				//&& pri > 0 && c < 0
				if( strlen(sp + i) < 2 && pri < 2 ){
					if( pri == 1 && l_pri == 1){
						sprintf(work,"%s%s%s",work3,work2,"　\n");
						strcpy( work3,work );
					}
					else {
						work3[ 0 ] = '\0';
						pri = 0;
					}
					//strcpy(work3,"");
					//printf("\n 通った");
				}
				else {
					sprintf(work,"%s%s%s",work3,work2,(sp + i));
					strcpy( work3,work );
				}
			}
			else if( strncmp(work3,"INPUT",5) == 0
			||  (sp = strstr(work3," INPUT")) != NULL
			||  (sp = strstr(work3,"	INPUT")) != NULL
			||  strncmp(work3,"ONEINPUT",8) == 0
			||  (sp = strstr(work3," ONEINPUT")) != NULL
			||  (sp = strstr(work3,"	ONEINPUT")) != NULL ){
					fputs(kuuhaku,fpw);
					fputs("CALL 口上変数表\示,,1\n",fpw);
					fputs(kuuhaku,fpw);
					fputs("CALL 口上変数初期化\n",fpw);
			}
			/*else if( (sp = strstr(work3,"INPUT")) != NULL){
				fputs(kuuhaku,fpw);
				fputs("CALL 口上変数表\示\n",fpw);
				fputs(kuuhaku,fpw);
				fputs("CALL 口上変数初期化\n",fpw);
			}*/
		}
		if((sp = strstr(work3,"CASE")) != NULL && mode == 10 )
			casen = atoi( sp + 5);
		if ( mode > 2){
			if( (strncmp(work3,"IF",2) == 0) ||
				(sp = strstr(work3," IF")) != NULL ||
				(sp = strstr(work3,"	IF")) != NULL ){
				if( if_in < 1 && (mode == 6 || mode == 9))
					fputs("LOCAL = K\n",fpw);
				if_in++;
				if( (sp = strstr(work3," TALENT:3")) != NULL || (sp = strstr(work3," TALENT:恋慕")) != NULL
				||	(sp = strstr(work3," TALENT:4")) != NULL || (sp = strstr(work3," TALENT:淫乱")) != NULL
				||	(sp = strstr(work3," TALENT:5")) != NULL || (sp = strstr(work3," TALENT:服従")) != NULL
				||	(sp = strstr(work3," TALENT:6")) != NULL || (sp = strstr(work3," TALENT:親愛")) != NULL
				||	(sp = strstr(work3," TALENT:7")) != NULL || (sp = strstr(work3," TALENT:娼婦")) != NULL
				||	(sp = strstr(work3," TALENT:8")) != NULL || (sp = strstr(work3," TALENT:隷属")) != NULL )
					ifc_in[ if_in ] = 1;
			}
			if( strncmp(work3,"ENDIF",5) == 0
			||  (sp = strstr(work3," ENDIF")) != NULL
			||  (sp = strstr(work3,"	ENDIF")) != NULL ){
				ifc_in[ if_in ] = 0;
				if_in--;
				if( if_in < 1 && mode == 6 )
					kmore = 1;
				else if( if_in < 1 && mode == 9 && markm[ 0 ] != '\0'){
					fputs("	SIF !口上有無確認(LOCAL)\n",fpw);
					fputs("		CALL ",fpw);
					fputs( markm,fpw);
					markm[ 0 ] = '\0';
				}
					
			}
			if((sp = strstr(work3,"ELSEIF")) != NULL ){
				if( (sp = strstr(work3," TALENT:3")) != NULL || (sp = strstr(work3," TALENT:恋慕")) != NULL
				||	(sp = strstr(work3," TALENT:4")) != NULL || (sp = strstr(work3," TALENT:淫乱")) != NULL
				||	(sp = strstr(work3," TALENT:5")) != NULL || (sp = strstr(work3," TALENT:服従")) != NULL
				||	(sp = strstr(work3," TALENT:6")) != NULL || (sp = strstr(work3," TALENT:親愛")) != NULL
				||	(sp = strstr(work3," TALENT:7")) != NULL || (sp = strstr(work3," TALENT:娼婦")) != NULL
				||	(sp = strstr(work3," TALENT:8")) != NULL || (sp = strstr(work3," TALENT:隷属")) != NULL )
					ifc_in[ if_in ] = 1;
				if((sp = strstr(work3,"CFLAG:")) != NULL ){
					strncpy( cflag,sp,9 );
					if( (sp = strstr(work3,"||")) != NULL &&
						strcspn(work3,"()") == strlen(work3)){
						sp = strstr(work3,"IF");
						sp2 = strstr(work3,"\n");
						if((*sp2) == '\n')
							(*sp2) = '\0';
						sprintf(work,"(%s)",sp + 3);
						*(sp + 3) = '\0';
						strcat( work3,work );
						if(c < 1)
							strcat( work3,"\n");
					}
					sprintf(work,"%sENDIF\n",kuuhaku);
					fputs(work,fpw);
					sp = strstr(work3,"IF");
					sp2 = strstr(work3,"\n");
					if((*sp2) == '\n')
						(*sp2) = '\0';
					if( mode == 6 || mode == 9 )
						sprintf(work,"%s%s && !口上有無確認(LOCAL)",kuuhaku,sp);
					else
						sprintf(work,"%s%s && !口上有無確認(0)",kuuhaku,sp);
					if(c < 1)
						strcat( work,"\n");
					strcpy( work3,work );
				}
				else if( if_in > 2 && mode == 7 ) {
					if( (sp = strstr(work3,"||")) != NULL &&
						strcspn(work3,"()") == strlen(work3)){
						sp = strstr(work3,"IF");
						sp2 = strstr(work3,"\n");
						if((*sp2) == '\n')
							(*sp2) = '\0';
						sprintf(work,"(%s)",sp + 3);
						*(sp + 3) = '\0';
						strcat( work3,work );
						if(c < 1)
							strcat( work3,"\n");
					}
					sprintf(work,"%sENDIF\n",kuuhaku);
					fputs(work,fpw);
					sp = strstr(work3,"IF");
					sp2 = strstr(work3,"\n");
					if((*sp2) == '\n')
						(*sp2) = '\0';
					if( mode == 6 || mode == 9 )
						sprintf(work,"%s%s && !口上有無確認(LOCAL)",kuuhaku,sp);
					else
						sprintf(work,"%s%s && !口上有無確認(0)",kuuhaku,sp);
					if(c < 1)
						strcat( work,"\n");
					strcpy( work3,work );
				}
			}
			else if((sp = strstr(work3,"ELSE")) != NULL ){
				if(( if_in == 2 && mode == 9 )
				|| ( if_in > 2 && mode == 7 ) 
				|| ( if_in > 1 && mode == 8 ) 
				|| ( ifc_in[ if_in ] > 0 ) 
				|| ( if_in == 1 && mode == 10 && casen != 13 ) ){
					sprintf(work,"%sENDIF\n",kuuhaku);
					fputs(work,fpw);
					if( mode == 6 || mode == 9 )
						sprintf(work,"%sIF !口上有無確認(LOCAL)",kuuhaku);
					else
						sprintf(work,"%sIF !口上有無確認(0)",kuuhaku);
					if(c < 1)
						strcat( work,"\n");
					strcpy( work3,work );
				}
			}
		}
		
		
		if ( mode > 1){
			if((sp = strstr(work3,"RETURN")) != NULL ){
				strcpy( sp,"GOTO 表\示");
				if(c < 1)
					strcat( work3,"\n");
			}
		}
		l_pri = pri;
		fputs(work3,fpw);
		if(c > 0)
			fputs(com,fpw);
		if(kmore > 0){
			fputs("SIF 口上有無確認(LOCAL) && K > 0\n",fpw);
			fputs("	CALL WSTR書き込み,K - 1\n",fpw);
		}
		//w++;
		//printf("\n %d",w);
    	//fgets(work3,255,fp);
    }
	
    fclose(fp);
    fclose(fpw);
	printf("\n 正常に終了しました",work3);
    scanf( "%s", work );
	
    return 0;
}
