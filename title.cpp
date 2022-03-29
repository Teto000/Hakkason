//====================
//タイトル
//autho　hamadaryuuga
//====================
#include "title.h"
#include "input.h"
//#include "sound.h"
#include "fade.h"
//#include "particle.h"

//画像の数
#define NUM_TITLE (9)

//スタティック
static LPDIRECT3DTEXTURE9 s_pTextureTitle[NUM_TITLE] = {}; //テクスチャのポインタ
static LPDIRECT3DVERTEXBUFFER9 s_pVtxBuffTitle = NULL; //頂点バッファの設定
static D3DXVECTOR3 s_moveTitle;	//移動量
static D3DXVECTOR3 s_posSelect;
static D3DXVECTOR3 s_posTitle[NUM_TITLE];	//座標
static TITLE s_Title[NUM_TITLE];//構造体
static int s_nTime;
static int s_nTime2;
static bool s_nTimeCut;



//================
//初期化処理
//================
void InitTitle(void)
{
	LPDIRECT3DDEVICE9  pDevice;
	int nCnt;
	s_moveTitle = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	s_posSelect = D3DXVECTOR3(0.0f, 450.0f, 0.0f);
	//デバイスの取得
	pDevice = GetDevice();

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\TITLE\\Title_BG.png",
		&s_pTextureTitle[0]);
	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data\\TEXTURE\\TITLE\\Title_Logo.png",
		&s_pTextureTitle[1]);
	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"Data/TEXTURE/Title002.png",
		&s_pTextureTitle[2]);
	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"Data/TEXTURE/STA.png",
		&s_pTextureTitle[3]);
	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"Data/TEXTURE/tutorial.png",
		&s_pTextureTitle[4]);
	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"Data/TEXTURE/ranking.png",
		&s_pTextureTitle[5]);
	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"Data/TEXTURE/Easy.png",
		&s_pTextureTitle[6]);
	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"Data/TEXTURE/Normal.png",
		&s_pTextureTitle[7]);
	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"Data/TEXTURE/Hard.png",
		&s_pTextureTitle[8]);

	s_nTime2 = 0;
	s_nTime = 0;

	//頂点バッファ
	pDevice->CreateVertexBuffer(
		sizeof(VERTEX_2D) * 4 * NUM_TITLE,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,//ここ頂点フォーマット
		&s_pVtxBuffTitle,
		NULL);

	//時間のやつ
	s_nTime = 0;
	s_nTimeCut = false;
	VERTEX_2D*pVtx; //頂点へのポインタ

					//頂点バッファをロックし頂点情報へのポインタを取得
	s_pVtxBuffTitle->Lock(0, 0, (void**)&pVtx, 0);
	for (nCnt = 0; nCnt < NUM_TITLE - 2; nCnt++)
	{
		s_Title[nCnt].degree = 0;
		s_Title[nCnt].nSwitch = false;
		s_posTitle[nCnt] = D3DXVECTOR3(0.0, 0.0, 0.0);
		s_Title[nCnt].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		if (nCnt == 2)
		{

			SetNormalpos(pVtx,
				0.0f,
				SCREEN_WIDTH,
				0.0f,
				1100.0f);

		}
		else if (nCnt >= 3 && nCnt <= 5)
		{
			SetNormalpos(pVtx,
				0.0f,
				SCREEN_WIDTH,
				s_posSelect.y - 200.0f,
				s_posSelect.y + 200.0f);
			s_posSelect += D3DXVECTOR3(0.0, 100.0, 0.0);
		}
		else if (nCnt == 6)
		{

			s_posSelect = D3DXVECTOR3(0.0, 400.0, 0.0);
			SetNormalpos(pVtx,
				100.0f,
				SCREEN_WIDTH,
				s_posSelect.y - 200.0f,
				s_posSelect.y + 200.0f);
		}
		else
		{
			SetNormalpos(pVtx,
				0.0f,
				SCREEN_WIDTH,
				0.0f,
				SCREEN_HEIGHT);

		}
		if (nCnt == 1)
		{

			SetNormalpos(pVtx,
				100.0f,
				1000,
				0.0f,
				1100.0f);

		}
		pVtx[0].rhw = 1.0f;
		pVtx[1].rhw = 1.0f;
		pVtx[2].rhw = 1.0f;
		pVtx[3].rhw = 1.0f;

		//頂点カラーの設定
		pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		Settex(pVtx, 0.0f, 1.0f, 0.0f, 1.0f);
		pVtx += 4;
	}

	//サウンド開始
	//PlaySound(SOUND_LABEL_BGM001);
	//頂点バッファをアンロック
	s_pVtxBuffTitle->Unlock();


}

//破棄
void UninitTitle(void)
{


	//サウンド停止
	//StopSound();
	int nCnt;
	//テクスチャの破棄
	for (nCnt = 0; nCnt < NUM_TITLE; nCnt++)
	{
		if (s_pTextureTitle[nCnt] != NULL)
		{
			s_pTextureTitle[nCnt]->Release();
			s_pTextureTitle[nCnt] = NULL;
		}
		//頂点バッファの破棄

		if (s_pVtxBuffTitle != NULL)
		{
			s_pVtxBuffTitle->Release();
			s_pVtxBuffTitle = NULL;
		}


	}
}
//==================
//更新処理
//==================
void UpdateTitle(void)
{
	int nCnt;

	VERTEX_2D*pVtx; //頂点へのポインタ
					//頂点バッファをロックし頂点情報へのポインタを取得
	s_pVtxBuffTitle->Lock(0, 0, (void**)&pVtx, 0);

	//タイトルが動く処理
	s_nTime++;
	s_nTime %= 40;

	////無限によこにプレスエンターが動く処理
	//s_posTitle[2].x += 0.008f;


	FADE pFade;
	pFade = GetFade();
	for (nCnt = 0; nCnt < NUM_TITLE - 2; nCnt++)
	{
		if (s_Title[nCnt].nSwitch == false)
		{
			if (s_nTime >= 20)
			{
				s_Title[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
			}
			else
			{

				s_Title[2].col = D3DXCOLOR(1.0f, 0.0f, 1.0f, 1.0f);
			}
		}
		if (s_Title[nCnt].nSwitch == true)
		{
			if ((GetKeyboardTrigger(DIK_W) ||
				GetKeyboardTrigger(JOYKEY_UP)) && pFade == FADE_NONE)
			{//上おした減算
				s_Title[nCnt].nSelect--;
				//PlaySound(SOUND_LABEL_SE_MOVE);
				if (s_Title[nCnt].nSelect < 0)
				{
					s_Title[nCnt].nSelect = 2;
				}
			}
			else if ((GetKeyboardTrigger(DIK_S) ||
				GetKeyboardTrigger(JOYKEY_DOWN)) && pFade == FADE_NONE)
			{//したキー加算
				s_Title[nCnt].nSelect++;
				//PlaySound(SOUND_LABEL_SE_MOVE);
				if (s_Title[nCnt].nSelect >= 3)
				{
					s_Title[nCnt].nSelect = 0;
				}
			}
			if ((GetKeyboardTrigger(DIK_A) ||
				GetKeyboardTrigger(JOYKEY_UP)) && pFade == FADE_NONE)
			{//上おした減算
				s_Title[nCnt].degree--;
				//PlaySound(SOUND_LABEL_SE_MOVE);
				if (s_Title[nCnt].degree < 0)
				{
					s_Title[nCnt].degree = 2;
				}
			}
			else if ((GetKeyboardTrigger(DIK_D) ||
				GetKeyboardTrigger(JOYKEY_DOWN)) && pFade == FADE_NONE)
			{//したキー加算
				s_Title[nCnt].degree++;
				//PlaySound(SOUND_LABEL_SE_MOVE);
				if (s_Title[nCnt].degree >= 3)
				{
					s_Title[nCnt].degree = 0;
				}
			}

			if ((GetKeyboardTrigger(DIK_RETURN) ||
				GetKeyboardTrigger(JOYKEY_B)) && pFade == FADE_NONE)
			{
				//メニューの内容
				switch (s_Title[nCnt].nSelect)
				{
				case 0://開始

				{ //SPACEを押されたとき
				  //PlaySound(SOUND_LABEL_SE_ENTER);
					SetFade(MODE_GAME);

				}
				break;
				case 1://チュートリアル

				{//SPACEを押されたとき
				 //PlaySound(SOUND_LABEL_SE_ENTER);
					//SetFade(MODE_TUTORIAL);

				}
				break;
				case 2://らんきんぐにいく

				{ //SPACEを押されたとき
				  //PlaySound(SOUND_LABEL_SE_ENTER);
					//SetFade(MODE_RANKING);
				}
				break;
				}
			}

		}
		if (((GetKeyboardTrigger(DIK_RETURN)
			|| GetKeyboardTrigger(JOYKEY_START))
			&& s_Title[nCnt].nSwitch == false)
			&& pFade == FADE_NONE)
		{//エンターを押されたとき
			s_Title[nCnt].nSwitch = true;
			s_Title[nCnt].col = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);
			//PlaySound(SOUND_LABEL_SE_MENU);
			s_Title[nCnt].nSelect = 0;
		}
		s_posTitle[nCnt] += s_moveTitle;
		Settex(pVtx, 0.0f + s_posTitle[nCnt].x, 1.0f + s_posTitle[nCnt].x, 0.0f + s_posTitle[nCnt].y, 1.0f + s_posTitle[nCnt].y);


		////移動量を更新(減衰させる)
		//s_moveTitle.x += (0.0f - s_moveTitle.x)*0.5f;//（目的の値-現在の値）＊減衰係数
		//s_moveTitle.y += (0.0f - s_moveTitle.y)*0.5f;
		if (nCnt == 1)
		{
			SetNormalpos(pVtx,
				0.0f - s_posTitle[1].x,
				1300.0f + s_posTitle[1].x,
				50.0f - s_posTitle[1].y,
				520.0f + s_posTitle[1].y);


		}
		if (!s_Title[nCnt].nSwitch)
		{
			if (nCnt == 2)
			{
				//頂点カラーの設定
				pVtx[0].col = s_Title[nCnt].col;
				pVtx[1].col = s_Title[nCnt].col;
				pVtx[2].col = s_Title[nCnt].col;
				pVtx[3].col = s_Title[nCnt].col;
			}
			else if (nCnt >= 3)
			{
				//頂点カラーの設定
				pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f);
				pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f);
				pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f);
				pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f);
			}
			else
			{
				//頂点カラーの設定
				pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
				pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
				pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
				pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
			}

		}
		else
		{
			//頂点カラーの設定
			if (nCnt == 2)
			{
				pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f);
				pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f);
				pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f);
				pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f);
			}
			else if (nCnt == s_Title[nCnt].nSelect + 3)
			{
				//頂点カラーの設定
				pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
				pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
				pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
				pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

			}
			else
			{
				//頂点カラーの設定
				pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.6f);
				pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.6f);
				pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.6f);
				pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.6f);

			}
		}
		pVtx += 4;
	}
	//頂点バッファをアンロック
	s_pVtxBuffTitle->Unlock();



#ifdef _DEBUG

	if (GetKeyboardPress(DIK_0))
	{
		SetFade(MODE_RESULT);
	}
	if (GetKeyboardPress(DIK_9))
	{
		//SetFade(MODE_GAMEOVER);
	}

#endif // DEBUG
}
//==================
//描画処理
//==================
void DrawTitle(void)
{
	int nCnt;

	LPDIRECT3DDEVICE9 pDevice;//デバイスのポインタ

	pDevice = GetDevice(); //代入

						   //頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, s_pVtxBuffTitle, 0, sizeof(VERTEX_2D));

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);

	//テクスチャの描画
	for (nCnt = 0; nCnt < NUM_TITLE - 3; nCnt++)
	{

		//テクスチャの設定
		pDevice->SetTexture(0, s_pTextureTitle[nCnt]);

		//ポリゴンの描画 四角
		pDevice->DrawPrimitive(
			D3DPT_TRIANGLESTRIP,		//プリミティブの種類
			nCnt * 4,			//描画する最初の頂点インデックス
			2);							//プリミティブ(ポリゴン)数
	}

	//テクスチャの設定
	pDevice->SetTexture(0, s_pTextureTitle[s_Title[nCnt].degree + nCnt]);

	//ポリゴンの描画 四角
	pDevice->DrawPrimitive(
		D3DPT_TRIANGLESTRIP,		//プリミティブの種類
		nCnt * 4, 2);			//描画する最初の頂点インデックス


}

int Getdegree(void)
{
	return s_Title[0].degree;
}