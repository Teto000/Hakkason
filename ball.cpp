////=================
////弾設定
////hamada ryuuga
////=================
//
//#include"ball.h"
//#include"game.h"
//
//
//#define	NUR_BULLET	(6)
//
////グローバル関数
//LPDIRECT3DTEXTURE9 g_pTextureBullet[NUR_BULLET] = {}; //テクスチャのポインタ
//LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffBullet = NULL; //頂点バッファの設定
//Bullet g_aBullet[MAX_BULLET];
//float coleff;//エフェクトの色
//float coleff2;//エフェクトの色
//int timaeff;//時間
////==================
////たまの初期化設定
////==================
//void InitBullet(void)
//{
//	LPDIRECT3DDEVICE9  pDevice;
//	int nCntBullet;
//
//	//デバイスの取得
//	pDevice = GetDevice();
//
//	//テクスチャの読み込み
//	D3DXCreateTextureFromFile(pDevice,
//		"Data/TEXTURE/bullet000.png",
//		&g_pTextureBullet[0]);
//	//テクスチャの読み込み
//	D3DXCreateTextureFromFile(pDevice,
//		"Data/TEXTURE/bullet001.png",
//		&g_pTextureBullet[1]);
//	//テクスチャの読み込み
//	D3DXCreateTextureFromFile(pDevice,
//		"Data/TEXTURE/bullet002.png",
//		&g_pTextureBullet[2]);
//	//テクスチャの読み込み
//	D3DXCreateTextureFromFile(pDevice,
//		"Data/TEXTURE/bullet003.png",
//		&g_pTextureBullet[3]);
//	//テクスチャの読み込み(敵のたま)
//	D3DXCreateTextureFromFile(pDevice,
//		"Data/TEXTURE/bullet004.png",
//		&g_pTextureBullet[4]);
//	//テクスチャの読み込み(ボス戦用の弾)
//	D3DXCreateTextureFromFile(pDevice,
//		"Data/TEXTURE/bullet005.png",
//		&g_pTextureBullet[5]);
//	coleff = 1.0f;
//	coleff2 = 0.0f;
//	timaeff = 0;
//	//初期化
//	for (nCntBullet = 0; nCntBullet < MAX_BULLET; nCntBullet++)
//	{
//		g_aBullet[nCntBullet].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);//ポス
//		g_aBullet[nCntBullet].move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);//ムーブ
//		g_aBullet[nCntBullet].nLife = 0;//ライフ
//		g_aBullet[nCntBullet].bUse = false;//使ってるか
//		g_aBullet[nCntBullet].Trigger = 0;   //種類
//		g_aBullet[nCntBullet].nType = 0;//タイプ
//		g_aBullet[nCntBullet].fSiz = 0.0f; //サイズ
//		g_aBullet[nCntBullet].Move2 = 0;
//	}
//
//	//頂点バッファ
//	pDevice->CreateVertexBuffer(
//		sizeof(VERTEX_2D) * 4 * MAX_BULLET,
//		D3DUSAGE_WRITEONLY,
//		FVF_VERTEX_2D,
//		D3DPOOL_MANAGED,//ここ頂点フォーマット
//		&g_pVtxBuffBullet,
//		NULL);
//
//	VERTEX_2D*pVtx; //頂点へのポインタ
//	g_pVtxBuffBullet->Lock(0, 0, (void**)&pVtx, 0);
//
//	//頂点バッファをロックし頂点情報へのポインタを取得
//	for (nCntBullet = 0; nCntBullet < MAX_BULLET; nCntBullet++)
//	{
//		//頂点座標
//		pVtx[0].pos = D3DXVECTOR3(g_aBullet[nCntBullet].pos.x - g_aBullet[nCntBullet].fSiz, g_aBullet[nCntBullet].pos.y - g_aBullet[nCntBullet].fSiz, 0.0f);
//		pVtx[1].pos = D3DXVECTOR3(g_aBullet[nCntBullet].pos.x + g_aBullet[nCntBullet].fSiz, g_aBullet[nCntBullet].pos.y - g_aBullet[nCntBullet].fSiz, 0.0f);
//		pVtx[2].pos = D3DXVECTOR3(g_aBullet[nCntBullet].pos.x - g_aBullet[nCntBullet].fSiz, g_aBullet[nCntBullet].pos.y + g_aBullet[nCntBullet].fSiz, 0.0f);
//		pVtx[3].pos = D3DXVECTOR3(g_aBullet[nCntBullet].pos.x + g_aBullet[nCntBullet].fSiz, g_aBullet[nCntBullet].pos.y + g_aBullet[nCntBullet].fSiz, 0.0f);
//
//		//RHWの設定
//		pVtx[0].rhw = 1.0f;
//		pVtx[1].rhw = 1.0f;
//		pVtx[2].rhw = 1.0f;
//		pVtx[3].rhw = 1.0f;
//
//		//頂点カラーの設定
//		pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
//		pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
//		pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
//		pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
//
//		//テクスチャの座標設定
//		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
//		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
//		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
//		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);
//
//		pVtx += 4; //頂点ポイントを四つ進む
//	}
//
//	//頂点バッファをアンロック
//	g_pVtxBuffBullet->Unlock();
//
//}
//
////==================
////終了処理
////==================
//void UninitBullet(void)
//{
//	int nCntBullet;
//	for (nCntBullet = 0; nCntBullet < NUR_BULLET; nCntBullet++)
//	{
//		//テクスチャの破棄
//		if (g_pTextureBullet[nCntBullet] != NULL)
//		{
//			g_pTextureBullet[nCntBullet]->Release();
//			g_pTextureBullet[nCntBullet] = NULL;
//		}
//
//	}
//
//	//頂点バッファの破棄
//	if (g_pVtxBuffBullet != NULL)
//	{
//		g_pVtxBuffBullet->Release();
//		g_pVtxBuffBullet = NULL;
//	}
//
//}
//
////==================
////更新処理
////==================
//void UpdateBullet(void)
//{
//	int nCntBullet;
//	//エンジンシステム
//	coleff2 += 0.1f;
//	if (coleff2 >= 1.0f)
//	{
//		coleff2 = 0.0f;
//	}
//	//点滅システム
//	timaeff++;
//	if (timaeff == 1)
//	{
//		coleff -= 0.2f;
//	}
//	if (timaeff == 31)
//	{
//		coleff += 0.2f;
//	}
//	if (timaeff == 61)
//	{
//		timaeff = 0;
//	}
//	VERTEX_2D*pVtx; //頂点へのポインタ
//	g_pVtxBuffBullet->Lock(0, 0, (void**)&pVtx, 0);
//	for (nCntBullet = 0; nCntBullet < MAX_BULLET; nCntBullet++)
//	{
//
//
//		if (g_aBullet[nCntBullet].bUse == true)
//		{
//			if (g_aBullet[nCntBullet].nType == 4)
//			{
//				g_aBullet[nCntBullet].pos.x += sin(D3DX_PI*(g_aBullet[nCntBullet].Move2 - 100.0f) / 100.0f)*2.5;
//				g_aBullet[nCntBullet].pos.y += sin(D3DX_PI*(g_aBullet[nCntBullet].Move2 - 20.0f) / 100.0f)*2.5;
//				g_aBullet[nCntBullet].Move2++;
//				SetEffect(g_aBullet[nCntBullet].pos, D3DXCOLOR(coleff2, coleff2, coleff2, 1.0f), 20, 10);
//				pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, coleff);
//				pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, coleff);
//				pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, coleff);
//				pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, coleff);
//			}
//			else
//			{
//				SetEffect(g_aBullet[nCntBullet].pos, D3DXCOLOR(1.0f, 0.0f, 1.0f, 1.0f), 15, 10);
//			}
//
//			//エネミーのデータ取得
//			Enemy *pEnemy;
//			int nCntEnemy;
//			pEnemy = GetEnemy();
//
//			//ボスのデータ取得
//			Boss *pBoss;
//			pBoss = GetBoss();
//
//			//プレイヤーのデータ取得
//			Player *nPlaye;
//			nPlaye = GetPlayer();
//
//			//フェードデータ取得
//			FADE pFade;
//			pFade = GetFade();
//
//			//位置更新
//			g_aBullet[nCntBullet].pos += g_aBullet[nCntBullet].move;
//
//			//頂点座標
//			pVtx[0].pos = D3DXVECTOR3(g_aBullet[nCntBullet].pos.x - g_aBullet[nCntBullet].fSiz, g_aBullet[nCntBullet].pos.y - g_aBullet[nCntBullet].fSiz, 0.0f);
//			pVtx[1].pos = D3DXVECTOR3(g_aBullet[nCntBullet].pos.x + g_aBullet[nCntBullet].fSiz, g_aBullet[nCntBullet].pos.y - g_aBullet[nCntBullet].fSiz, 0.0f);
//			pVtx[2].pos = D3DXVECTOR3(g_aBullet[nCntBullet].pos.x - g_aBullet[nCntBullet].fSiz, g_aBullet[nCntBullet].pos.y + g_aBullet[nCntBullet].fSiz, 0.0f);
//			pVtx[3].pos = D3DXVECTOR3(g_aBullet[nCntBullet].pos.x + g_aBullet[nCntBullet].fSiz, g_aBullet[nCntBullet].pos.y + g_aBullet[nCntBullet].fSiz, 0.0f);
//
//
//			g_aBullet[nCntBullet].nLife--;
//
//			if (pVtx[0].pos.x >= SCREEN_WIDTH)
//			{
//				g_aBullet[nCntBullet].bUse = false;
//			}
//			if (pVtx[0].pos.y <= 100)
//			{
//				g_aBullet[nCntBullet].bUse = false;
//			}
//			if (g_aBullet[nCntBullet].nLife == 0)
//			{
//
//				g_aBullet[nCntBullet].bUse = false;
//
//			}
//			for (nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++, pEnemy++)
//			{
//				if (pEnemy->bUse == true)
//				{
//					if (pEnemy->nType == 0)
//					{//敵が使用されてる
//						if (g_aBullet[nCntBullet].nType == 0)
//						{
//							if (((g_aBullet[nCntBullet].pos.y) <= (pEnemy->pos.y + MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.y) >= (pEnemy->pos.y - MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.x) <= (pEnemy->pos.x + MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.x) >= (pEnemy->pos.x - MAX_SIZ)))
//							{//敵が使用されてる当たり判定
//								HitEnemy(nCntEnemy, 5);
//
//								g_aBullet[nCntBullet].bUse = false;
//							}
//						}
//						else if (g_aBullet[nCntBullet].nType == 1)
//						{
//							if (((g_aBullet[nCntBullet].pos.y) <= (pEnemy->pos.y + MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.y) >= (pEnemy->pos.y - MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.x) <= (pEnemy->pos.x + MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.x) >= (pEnemy->pos.x - MAX_SIZ)))
//							{//敵が使用されてる当たり判定
//								HitEnemy(nCntEnemy, 10);
//
//								g_aBullet[nCntBullet].bUse = false;
//							}
//						}
//						else if (g_aBullet[nCntBullet].nType == 2)
//						{
//							if (((g_aBullet[nCntBullet].pos.y) <= (pEnemy->pos.y + MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.y) >= (pEnemy->pos.y - MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.x) <= (pEnemy->pos.x + MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.x) >= (pEnemy->pos.x - MAX_SIZ)))
//							{//敵が使用されてる当たり判定
//								HitEnemy(nCntEnemy, 5);
//
//								g_aBullet[nCntBullet].bUse = false;
//							}
//						}
//						else if (g_aBullet[nCntBullet].nType == 3)
//						{
//							if (((g_aBullet[nCntBullet].pos.y) <= (pEnemy->pos.y + MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.y) >= (pEnemy->pos.y - MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.x) <= (pEnemy->pos.x + MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.x) >= (pEnemy->pos.x - MAX_SIZ)))
//							{//敵が使用されてる当たり判定
//								HitEnemy(nCntEnemy, 5);
//
//								g_aBullet[nCntBullet].bUse = false;
//							}
//						}
//
//
//					}
//					//=================================================
//					if (pEnemy->nType == 1)
//					{//敵が使用されてる
//						if (g_aBullet[nCntBullet].nType == 0)
//						{
//							if (((g_aBullet[nCntBullet].pos.y) <= (pEnemy->pos.y + MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.y) >= (pEnemy->pos.y - MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.x) <= (pEnemy->pos.x + MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.x) >= (pEnemy->pos.x - MAX_SIZ)))
//							{//敵が使用されてる当たり判定
//								HitEnemy(nCntEnemy, 5);
//
//								g_aBullet[nCntBullet].bUse = false;
//							}
//						}
//						else if (g_aBullet[nCntBullet].nType == 1)
//						{
//							if (((g_aBullet[nCntBullet].pos.y) <= (pEnemy->pos.y + MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.y) >= (pEnemy->pos.y - MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.x) <= (pEnemy->pos.x + MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.x) >= (pEnemy->pos.x - MAX_SIZ)))
//							{//敵が使用されてる当たり判定
//								HitEnemy(nCntEnemy, 10);
//
//								g_aBullet[nCntBullet].bUse = false;
//							}
//						}
//						else if (g_aBullet[nCntBullet].nType == 2)
//						{
//							if (((g_aBullet[nCntBullet].pos.y) <= (pEnemy->pos.y + MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.y) >= (pEnemy->pos.y - MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.x) <= (pEnemy->pos.x + MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.x) >= (pEnemy->pos.x - MAX_SIZ)))
//							{//敵が使用されてる当たり判定
//								HitEnemy(nCntEnemy, 2);
//
//								g_aBullet[nCntBullet].bUse = false;
//							}
//						}
//						else if (g_aBullet[nCntBullet].nType == 3)
//						{
//							if (((g_aBullet[nCntBullet].pos.y) <= (pEnemy->pos.y + MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.y) >= (pEnemy->pos.y - MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.x) <= (pEnemy->pos.x + MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.x) >= (pEnemy->pos.x - MAX_SIZ)))
//							{//敵が使用されてる当たり判定
//								HitEnemy(nCntEnemy, 2);
//
//								g_aBullet[nCntBullet].bUse = false;
//							}
//						}
//					}
//					//--------------------------------------------------
//					if (pEnemy->nType == 2)
//					{//敵が使用されてる
//						if (g_aBullet[nCntBullet].nType == 0)
//						{
//							if (((g_aBullet[nCntBullet].pos.y) <= (pEnemy->pos.y + MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.y) >= (pEnemy->pos.y - MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.x) <= (pEnemy->pos.x + MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.x) >= (pEnemy->pos.x - MAX_SIZ)))
//							{//敵が使用されてる当たり判定
//								HitEnemy(nCntEnemy, 5);
//
//								g_aBullet[nCntBullet].bUse = false;
//							}
//						}
//						else if (g_aBullet[nCntBullet].nType == 1)
//						{
//							if (((g_aBullet[nCntBullet].pos.y) <= (pEnemy->pos.y + MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.y) >= (pEnemy->pos.y - MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.x) <= (pEnemy->pos.x + MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.x) >= (pEnemy->pos.x - MAX_SIZ)))
//							{//敵が使用されてる当たり判定
//								HitEnemy(nCntEnemy, 10);
//
//								g_aBullet[nCntBullet].bUse = false;
//							}
//						}
//						else if (g_aBullet[nCntBullet].nType == 2)
//						{
//							if (((g_aBullet[nCntBullet].pos.y) <= (pEnemy->pos.y + MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.y) >= (pEnemy->pos.y - MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.x) <= (pEnemy->pos.x + MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.x) >= (pEnemy->pos.x - MAX_SIZ)))
//							{//敵が使用されてる当たり判定
//								HitEnemy(nCntEnemy, 1);
//
//								g_aBullet[nCntBullet].bUse = false;
//							}
//						}
//						else if (g_aBullet[nCntBullet].nType == 3)
//						{
//							if (((g_aBullet[nCntBullet].pos.y) <= (pEnemy->pos.y + MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.y) >= (pEnemy->pos.y - MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.x) <= (pEnemy->pos.x + MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.x) >= (pEnemy->pos.x - MAX_SIZ)))
//							{//敵が使用されてる当たり判定
//								HitEnemy(nCntEnemy, 1);
//
//								g_aBullet[nCntBullet].bUse = false;
//							}
//						}
//
//
//					}
//					//------------------------------------------------------
//					if (pEnemy->nType == 3)
//					{//敵が使用されてる
//						if (g_aBullet[nCntBullet].nType == 0)
//						{
//							if (((g_aBullet[nCntBullet].pos.y) <= (pEnemy->pos.y + MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.y) >= (pEnemy->pos.y - MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.x) <= (pEnemy->pos.x + MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.x) >= (pEnemy->pos.x - MAX_SIZ)))
//							{//敵が使用されてる当たり判定
//								HitEnemy(nCntEnemy, 5);
//
//								g_aBullet[nCntBullet].bUse = false;
//							}
//						}
//						else if (g_aBullet[nCntBullet].nType == 1)
//						{
//							if (((g_aBullet[nCntBullet].pos.y) <= (pEnemy->pos.y + MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.y) >= (pEnemy->pos.y - MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.x) <= (pEnemy->pos.x + MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.x) >= (pEnemy->pos.x - MAX_SIZ)))
//							{//敵が使用されてる当たり判定
//								HitEnemy(nCntEnemy, 5);
//
//								g_aBullet[nCntBullet].bUse = false;
//							}
//						}
//						else if (g_aBullet[nCntBullet].nType == 2)
//						{
//							if (((g_aBullet[nCntBullet].pos.y) <= (pEnemy->pos.y + MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.y) >= (pEnemy->pos.y - MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.x) <= (pEnemy->pos.x + MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.x) >= (pEnemy->pos.x - MAX_SIZ)))
//							{//敵が使用されてる当たり判定
//								HitEnemy(nCntEnemy, 1);
//
//								g_aBullet[nCntBullet].bUse = false;
//							}
//						}
//						else if (g_aBullet[nCntBullet].nType == 3)
//						{
//							if (((g_aBullet[nCntBullet].pos.y) <= (pEnemy->pos.y + MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.y) >= (pEnemy->pos.y - MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.x) <= (pEnemy->pos.x + MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.x) >= (pEnemy->pos.x - MAX_SIZ)))
//							{//敵が使用されてる当たり判定
//								HitEnemy(nCntEnemy, 1);
//
//								g_aBullet[nCntBullet].bUse = false;
//							}
//						}
//
//
//					}
//				}
//			}
//			//プレイヤーの当たり判定
//			if (g_aBullet[nCntBullet].nType == 4 && nPlaye->bUse == true)
//			{
//				if (((g_aBullet[nCntBullet].pos.y) <= (nPlaye->pos.y + 50.0f) &&
//					(g_aBullet[nCntBullet].pos.y) >= (nPlaye->pos.y - 50.0f) &&
//					(g_aBullet[nCntBullet].pos.x) <= (nPlaye->pos.x + 50.0f) &&
//					(g_aBullet[nCntBullet].pos.x) >= (nPlaye->pos.x - 50.0f)))
//				{//敵が使用されてる当たり判定
//					AddScore(100);
//					SetEffect(nPlaye->pos, D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f), 100, 15);
//					PlaySound(SOUND_LABEL_SE_ADD);
//					g_aBullet[nCntBullet].bUse = false;
//				}
//			}
//			if (pBoss->bUse == true && pBoss->bLife2 == true && pBoss->Inboss == false)
//			{
//				if (g_aBullet[nCntBullet].nType == 0)
//				{
//					if (((g_aBullet[nCntBullet].pos.y) <= (pBoss->pos.y + MAX_BOSSSIZ) &&
//						(g_aBullet[nCntBullet].pos.y) >= (pBoss->pos.y - MAX_BOSSSIZ) &&
//						(g_aBullet[nCntBullet].pos.x) <= (pBoss->pos.x + MAX_BOSSSIZ) &&
//						(g_aBullet[nCntBullet].pos.x) >= (pBoss->pos.x - MAX_BOSSSIZ)))
//					{//敵が使用されてる当たり判定
//						HitBoss(0);
//
//						g_aBullet[nCntBullet].bUse = false;
//					}
//				}
//				else if (g_aBullet[nCntBullet].nType == 1)
//				{
//					if (((g_aBullet[nCntBullet].pos.y) <= (pBoss->pos.y + MAX_BOSSSIZ) &&
//						(g_aBullet[nCntBullet].pos.y) >= (pBoss->pos.y - MAX_BOSSSIZ) &&
//						(g_aBullet[nCntBullet].pos.x) <= (pBoss->pos.x + MAX_BOSSSIZ) &&
//						(g_aBullet[nCntBullet].pos.x) >= (pBoss->pos.x - MAX_BOSSSIZ)))
//					{//敵が使用されてる当たり判定
//						HitBoss(0);
//
//						g_aBullet[nCntBullet].bUse = false;
//					}
//				}
//				else if (g_aBullet[nCntBullet].nType == 2)
//				{
//					if (((g_aBullet[nCntBullet].pos.y) <= (pBoss->pos.y + MAX_BOSSSIZ) &&
//						(g_aBullet[nCntBullet].pos.y) >= (pBoss->pos.y - MAX_BOSSSIZ) &&
//						(g_aBullet[nCntBullet].pos.x) <= (pBoss->pos.x + MAX_BOSSSIZ) &&
//						(g_aBullet[nCntBullet].pos.x) >= (pBoss->pos.x - MAX_BOSSSIZ)))
//					{//敵が使用されてる当たり判定
//						HitBoss(0);
//
//						g_aBullet[nCntBullet].bUse = false;
//					}
//				}
//				else if (g_aBullet[nCntBullet].nType == 3)
//				{
//					if (((g_aBullet[nCntBullet].pos.y) <= (pBoss->pos.y + MAX_BOSSSIZ) &&
//						(g_aBullet[nCntBullet].pos.y) >= (pBoss->pos.y - MAX_BOSSSIZ) &&
//						(g_aBullet[nCntBullet].pos.x) <= (pBoss->pos.x + MAX_BOSSSIZ) &&
//						(g_aBullet[nCntBullet].pos.x) >= (pBoss->pos.x - MAX_BOSSSIZ)))
//					{//敵が使用されてる当たり判定
//						HitBoss(0);
//
//						g_aBullet[nCntBullet].bUse = false;
//					}
//				}
//				else if (g_aBullet[nCntBullet].nType == 5)
//				{
//					if (((g_aBullet[nCntBullet].pos.y) <= (pBoss->pos.y + MAX_BOSSSIZ) &&
//						(g_aBullet[nCntBullet].pos.y) >= (pBoss->pos.y - MAX_BOSSSIZ) &&
//						(g_aBullet[nCntBullet].pos.x) <= (pBoss->pos.x + MAX_BOSSSIZ) &&
//						(g_aBullet[nCntBullet].pos.x) >= (pBoss->pos.x - MAX_BOSSSIZ)))
//					{//敵が使用されてる当たり判定
//						HitBoss(0);
//
//						g_aBullet[nCntBullet].bUse = false;
//					}
//				}
//			}
//			else if (pBoss->bUse == true && pBoss->bLife2 == true && pBoss->Inboss == true)
//			{//敵が使用されてる
//				if (g_aBullet[nCntBullet].nType == 0)
//				{
//					if (((g_aBullet[nCntBullet].pos.y) <= (pBoss->pos.y + MAX_BOSSSIZ) &&
//						(g_aBullet[nCntBullet].pos.y) >= (pBoss->pos.y - MAX_BOSSSIZ) &&
//						(g_aBullet[nCntBullet].pos.x) <= (pBoss->pos.x + MAX_BOSSSIZ) &&
//						(g_aBullet[nCntBullet].pos.x) >= (pBoss->pos.x - MAX_BOSSSIZ)))
//					{//敵が使用されてる当たり判定
//						HitBoss(10);
//
//						g_aBullet[nCntBullet].bUse = false;
//					}
//				}
//				else if (g_aBullet[nCntBullet].nType == 1)
//				{
//					if (((g_aBullet[nCntBullet].pos.y) <= (pBoss->pos.y + MAX_BOSSSIZ) &&
//						(g_aBullet[nCntBullet].pos.y) >= (pBoss->pos.y - MAX_BOSSSIZ) &&
//						(g_aBullet[nCntBullet].pos.x) <= (pBoss->pos.x + MAX_BOSSSIZ) &&
//						(g_aBullet[nCntBullet].pos.x) >= (pBoss->pos.x - MAX_BOSSSIZ)))
//					{//敵が使用されてる当たり判定
//						HitBoss(5);
//
//						g_aBullet[nCntBullet].bUse = false;
//					}
//				}
//				else if (g_aBullet[nCntBullet].nType == 2)
//				{
//					if (((g_aBullet[nCntBullet].pos.y) <= (pBoss->pos.y + MAX_BOSSSIZ) &&
//						(g_aBullet[nCntBullet].pos.y) >= (pBoss->pos.y - MAX_BOSSSIZ) &&
//						(g_aBullet[nCntBullet].pos.x) <= (pBoss->pos.x + MAX_BOSSSIZ) &&
//						(g_aBullet[nCntBullet].pos.x) >= (pBoss->pos.x - MAX_BOSSSIZ)))
//					{//敵が使用されてる当たり判定
//						HitBoss(5);
//
//						g_aBullet[nCntBullet].bUse = false;
//					}
//				}
//				else if (g_aBullet[nCntBullet].nType == 3)
//				{
//					if (((g_aBullet[nCntBullet].pos.y) <= (pBoss->pos.y + MAX_BOSSSIZ) &&
//						(g_aBullet[nCntBullet].pos.y) >= (pBoss->pos.y - MAX_BOSSSIZ) &&
//						(g_aBullet[nCntBullet].pos.x) <= (pBoss->pos.x + MAX_BOSSSIZ) &&
//						(g_aBullet[nCntBullet].pos.x) >= (pBoss->pos.x - MAX_BOSSSIZ)))
//					{//敵が使用されてる当たり判定
//						HitBoss(5);
//
//						g_aBullet[nCntBullet].bUse = false;
//					}
//				}
//				else if (g_aBullet[nCntBullet].nType == 5)
//				{
//					if (((g_aBullet[nCntBullet].pos.y) <= (pBoss->pos.y + MAX_BOSSSIZ) &&
//						(g_aBullet[nCntBullet].pos.y) >= (pBoss->pos.y - MAX_BOSSSIZ) &&
//						(g_aBullet[nCntBullet].pos.x) <= (pBoss->pos.x + MAX_BOSSSIZ) &&
//						(g_aBullet[nCntBullet].pos.x) >= (pBoss->pos.x - MAX_BOSSSIZ)))
//					{//敵が使用されてる当たり判定
//						HitBoss(10);
//
//						g_aBullet[nCntBullet].bUse = false;
//					}
//				}
//			}
//		}
//		pVtx += 4;//頂点ポイントを四つ進む
//	}
//	//頂点バッファをアンロック
//	g_pVtxBuffBullet->Unlock();
//}
//
////==================
////弾の描画処理
////==================
//void DrawBullet(void)
//{
//	LPDIRECT3DDEVICE9 pDevice;//デバイスのポインタ
//	int nCntBullet;
//
//	pDevice = GetDevice();		//代入
//
//								//頂点バッファをデータストリームに設定
//	pDevice->SetStreamSource(0, g_pVtxBuffBullet, 0, sizeof(VERTEX_2D));
//
//	//頂点フォーマットの設定
//	pDevice->SetFVF(FVF_VERTEX_2D);
//
//	for (nCntBullet = 0; nCntBullet < MAX_BULLET; nCntBullet++)
//	{
//		//テクスチャの設定
//		pDevice->SetTexture(0, g_pTextureBullet[g_aBullet[nCntBullet].nType]);
//
//		if (g_aBullet[nCntBullet].bUse == true)
//		{
//			pDevice->DrawPrimitive(
//				D3DPT_TRIANGLESTRIP,
//				nCntBullet * 4,
//				2);
//		}
//	}
//}
//
////==================
////弾の設定
////==================
//void SetBullet(D3DXVECTOR3 pos, D3DXVECTOR3 move, int nLife, int nType, float fSiz)
//{
//	int nCntBullet;
//	VERTEX_2D*pVtx; //頂点へのポインタ
//
//					//ロック
//	g_pVtxBuffBullet->Lock(0, 0, (void**)&pVtx, 0);
//
//	for (nCntBullet = 0; nCntBullet <MAX_BULLET; nCntBullet++)
//	{
//		if (g_aBullet[nCntBullet].bUse == false)
//		{
//			//弾が使用されてない場合
//			g_aBullet[nCntBullet].pos.x = pos.x;
//			g_aBullet[nCntBullet].pos.y = pos.y;
//			g_aBullet[nCntBullet].pos.z = pos.z;
//
//			g_aBullet[nCntBullet].fSiz = fSiz;
//			//頂点座標
//			pVtx[0].pos = D3DXVECTOR3(g_aBullet[nCntBullet].pos.x - fSiz, g_aBullet[nCntBullet].pos.y - fSiz, 0.0f);
//			pVtx[1].pos = D3DXVECTOR3(g_aBullet[nCntBullet].pos.x + fSiz, g_aBullet[nCntBullet].pos.y - fSiz, 0.0f);
//			pVtx[2].pos = D3DXVECTOR3(g_aBullet[nCntBullet].pos.x - fSiz, g_aBullet[nCntBullet].pos.y + fSiz, 0.0f);
//			pVtx[3].pos = D3DXVECTOR3(g_aBullet[nCntBullet].pos.x + fSiz, g_aBullet[nCntBullet].pos.y + fSiz, 0.0f);
//			g_aBullet[nCntBullet].move = move;
//			g_aBullet[nCntBullet].nLife = nLife;
//			g_aBullet[nCntBullet].bUse = true;
//			g_aBullet[nCntBullet].nType = nType;
//			break;
//		}
//		pVtx += 4;
//	}
//	//頂点バッファをアンロック
//	g_pVtxBuffBullet->Unlock();
//}
