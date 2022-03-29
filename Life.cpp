//------------------------
// インクルード
#include "Life.h"
#include "enemy.h"

#define KINDS (1)	//テクスチャ種類

#define SIZ_X (50)	//サイズX
#define SIZ_Y (50)	//サイズY

static LPDIRECT3DTEXTURE9 s_TextureLife[KINDS] = {};			//テクスチャへのポインタ
static LPDIRECT3DVERTEXBUFFER9 s_PvtxBuffLife = NULL;				//頂点バッファへのポインタ
static Life s_Life[MAX_Life];



void InitLife(void)
{
	//デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	//テクスチャ読み込み	敵テクスチャ
	D3DXCreateTextureFromFile(pDevice,
		"t",				//ライフ
		&s_TextureLife[0]);

	//頂点バッファの生成
	pDevice->CreateVertexBuffer
	(sizeof(VERTEX_2D) * 4 * MAX_Life,	//確保するバッファサイズ
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,		//頂点フォーマット
		D3DPOOL_MANAGED,
		&s_PvtxBuffLife,
		NULL);

	for (int Cnt = 0; Cnt < MAX_Life; Cnt++)
	{//初期化
		s_Life[Cnt].move = D3DXVECTOR3 (0.0f, 0.0f, 0.0f);			//移動量
		s_Life[Cnt].pos  = D3DXVECTOR3 (0.0f, 0.0f, 0.0f);			//位置
		s_Life[Cnt].col = D3DXCOLOR (0.0f, 0.0f, 0.0f,0.0f);

		int nLife = 0;					//体力
		bool bUse = false;					//使用してるかどうか	
	}

	VERTEX_2D*pVtx;

	//頂点バッファをロックし、頂点データへのポインタを取得
	s_PvtxBuffLife->Lock(0, 0, (void**)&pVtx, 0);

	for (int Cnt = 0; Cnt < MAX_Life; Cnt++, pVtx += 4)
	{

		//頂点座標の設定
		pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(100.0f, 0.0f, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(0.0f, 100.0f, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(100.0f, 100.0f, 0.0f);

		//rhwの設定
		pVtx[0].rhw = 1.0f;
		pVtx[1].rhw = 1.0f;
		pVtx[2].rhw = 1.0f;
		pVtx[3].rhw = 1.0f;

		//頂点カラーの設定
		pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		//テクスチャ座標の設定
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);
	}
		//頂点をアンロックする
		s_PvtxBuffLife->Unlock();

		
		SetEnemy(D3DXVECTOR3(100.0f, 100.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), 1);
		SetEnemy(D3DXVECTOR3(300.0f, 100.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), 1);

		SetEnemy(D3DXVECTOR3(500.0f, 100.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), 1);
		SetEnemy(D3DXVECTOR3(700.0f, 100.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), 1);


}
void UninitLife(void)
{
	for (int count = 0; count < KINDS; count++)
	{
		if (s_TextureLife[count] != NULL)
		{
			s_TextureLife[count]->Release();
			s_TextureLife[count] = NULL;
		}
	}
	//頂点バッファ破棄
	if (s_PvtxBuffLife != NULL)
	{
		s_PvtxBuffLife->Release();
		s_PvtxBuffLife = NULL;
	}

}
void UpdateLife(void)
{
	for (int nCnt = 0; nCnt < MAX_Life; nCnt++)
	{
		if (s_Life[Cnt].pos.x + 25 >= pPlayer->pos.x - 25
			&& s_Life[Cnt].pos.x - 25 <= pPlayer->pos.x + 25
			&& s_Life[Cnt].pos.y + 25 >= pPlayer->pos.y - 25
			&& s_Life[Cnt].pos.y - 25 <= pPlayer->pos.y + 25)
		{//弾座標重なり

		

		}
	}
}
void DrawLife(void)
{
	//デバイスの取得
	LPDIRECT3DDEVICE9	pDevice = GetDevice();

	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, s_PvtxBuffLife, 0, sizeof(VERTEX_2D));

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);

	for (int nCnt = 0; nCnt < MAX_Life; nCnt++)
	{
		//テクスチャの設定
		pDevice->SetTexture(0, s_TextureLife[0]);

		if (s_Life[nCnt].bUse)
		{
		 //ポリゴンの描画
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,
				nCnt * 4,
				2);
		}
	}
}
void SetEnemy(D3DXVECTOR3 pos, D3DXCOLOR col, int fLife)
{

	VERTEX_2D*pVtx;

	//頂点バッファをロックし、頂点データへのポインタを取得
	s_PvtxBuffLife->Lock(0, 0, (void**)&pVtx, 0);

	for (int Cnt = 0; Cnt < MAX_Life; Cnt++)
	{
		if (!s_Life[Cnt].bUse)
		{
			s_Life[Cnt].pos = pos;

			//頂点座標の設定
			pVtx[0].pos.x = s_Life[Cnt].pos.x - SIZ_X;
			pVtx[0].pos.y = s_Life[Cnt].pos.y - SIZ_Y;
			pVtx[0].pos.z = 0.0f;

			pVtx[1].pos.x = s_Life[Cnt].pos.x + SIZ_X;
			pVtx[1].pos.y = s_Life[Cnt].pos.y - SIZ_Y;
			pVtx[1].pos.z = 0.0f;

			pVtx[2].pos.x = s_Life[Cnt].pos.x - SIZ_X;
			pVtx[2].pos.y = s_Life[Cnt].pos.y + SIZ_Y;
			pVtx[2].pos.z = 0.0f;

			pVtx[3].pos.x = s_Life[Cnt].pos.x + SIZ_X;
			pVtx[3].pos.y = s_Life[Cnt].pos.y + SIZ_Y;
			pVtx[3].pos.z = 0.0f;

			s_Life[Cnt].nLife = fLife;
			s_Life[Cnt].col = col;
			s_Life[Cnt].bUse = true;
			break;
		}
		pVtx += 4;	//頂点座標データのポインタを４つ分進める
	}
	//頂点をアンロックする
	s_PvtxBuffLife->Unlock();
}