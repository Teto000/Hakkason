////=================
////�e�ݒ�
////hamada ryuuga
////=================
//
//#include"ball.h"
//#include"game.h"
//
//
//#define	NUR_BULLET	(6)
//
////�O���[�o���֐�
//LPDIRECT3DTEXTURE9 g_pTextureBullet[NUR_BULLET] = {}; //�e�N�X�`���̃|�C���^
//LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffBullet = NULL; //���_�o�b�t�@�̐ݒ�
//Bullet g_aBullet[MAX_BULLET];
//float coleff;//�G�t�F�N�g�̐F
//float coleff2;//�G�t�F�N�g�̐F
//int timaeff;//����
////==================
////���܂̏������ݒ�
////==================
//void InitBullet(void)
//{
//	LPDIRECT3DDEVICE9  pDevice;
//	int nCntBullet;
//
//	//�f�o�C�X�̎擾
//	pDevice = GetDevice();
//
//	//�e�N�X�`���̓ǂݍ���
//	D3DXCreateTextureFromFile(pDevice,
//		"Data/TEXTURE/bullet000.png",
//		&g_pTextureBullet[0]);
//	//�e�N�X�`���̓ǂݍ���
//	D3DXCreateTextureFromFile(pDevice,
//		"Data/TEXTURE/bullet001.png",
//		&g_pTextureBullet[1]);
//	//�e�N�X�`���̓ǂݍ���
//	D3DXCreateTextureFromFile(pDevice,
//		"Data/TEXTURE/bullet002.png",
//		&g_pTextureBullet[2]);
//	//�e�N�X�`���̓ǂݍ���
//	D3DXCreateTextureFromFile(pDevice,
//		"Data/TEXTURE/bullet003.png",
//		&g_pTextureBullet[3]);
//	//�e�N�X�`���̓ǂݍ���(�G�̂���)
//	D3DXCreateTextureFromFile(pDevice,
//		"Data/TEXTURE/bullet004.png",
//		&g_pTextureBullet[4]);
//	//�e�N�X�`���̓ǂݍ���(�{�X��p�̒e)
//	D3DXCreateTextureFromFile(pDevice,
//		"Data/TEXTURE/bullet005.png",
//		&g_pTextureBullet[5]);
//	coleff = 1.0f;
//	coleff2 = 0.0f;
//	timaeff = 0;
//	//������
//	for (nCntBullet = 0; nCntBullet < MAX_BULLET; nCntBullet++)
//	{
//		g_aBullet[nCntBullet].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);//�|�X
//		g_aBullet[nCntBullet].move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);//���[�u
//		g_aBullet[nCntBullet].nLife = 0;//���C�t
//		g_aBullet[nCntBullet].bUse = false;//�g���Ă邩
//		g_aBullet[nCntBullet].Trigger = 0;   //���
//		g_aBullet[nCntBullet].nType = 0;//�^�C�v
//		g_aBullet[nCntBullet].fSiz = 0.0f; //�T�C�Y
//		g_aBullet[nCntBullet].Move2 = 0;
//	}
//
//	//���_�o�b�t�@
//	pDevice->CreateVertexBuffer(
//		sizeof(VERTEX_2D) * 4 * MAX_BULLET,
//		D3DUSAGE_WRITEONLY,
//		FVF_VERTEX_2D,
//		D3DPOOL_MANAGED,//�������_�t�H�[�}�b�g
//		&g_pVtxBuffBullet,
//		NULL);
//
//	VERTEX_2D*pVtx; //���_�ւ̃|�C���^
//	g_pVtxBuffBullet->Lock(0, 0, (void**)&pVtx, 0);
//
//	//���_�o�b�t�@�����b�N�����_���ւ̃|�C���^���擾
//	for (nCntBullet = 0; nCntBullet < MAX_BULLET; nCntBullet++)
//	{
//		//���_���W
//		pVtx[0].pos = D3DXVECTOR3(g_aBullet[nCntBullet].pos.x - g_aBullet[nCntBullet].fSiz, g_aBullet[nCntBullet].pos.y - g_aBullet[nCntBullet].fSiz, 0.0f);
//		pVtx[1].pos = D3DXVECTOR3(g_aBullet[nCntBullet].pos.x + g_aBullet[nCntBullet].fSiz, g_aBullet[nCntBullet].pos.y - g_aBullet[nCntBullet].fSiz, 0.0f);
//		pVtx[2].pos = D3DXVECTOR3(g_aBullet[nCntBullet].pos.x - g_aBullet[nCntBullet].fSiz, g_aBullet[nCntBullet].pos.y + g_aBullet[nCntBullet].fSiz, 0.0f);
//		pVtx[3].pos = D3DXVECTOR3(g_aBullet[nCntBullet].pos.x + g_aBullet[nCntBullet].fSiz, g_aBullet[nCntBullet].pos.y + g_aBullet[nCntBullet].fSiz, 0.0f);
//
//		//RHW�̐ݒ�
//		pVtx[0].rhw = 1.0f;
//		pVtx[1].rhw = 1.0f;
//		pVtx[2].rhw = 1.0f;
//		pVtx[3].rhw = 1.0f;
//
//		//���_�J���[�̐ݒ�
//		pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
//		pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
//		pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
//		pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
//
//		//�e�N�X�`���̍��W�ݒ�
//		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
//		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
//		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
//		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);
//
//		pVtx += 4; //���_�|�C���g���l�i��
//	}
//
//	//���_�o�b�t�@���A�����b�N
//	g_pVtxBuffBullet->Unlock();
//
//}
//
////==================
////�I������
////==================
//void UninitBullet(void)
//{
//	int nCntBullet;
//	for (nCntBullet = 0; nCntBullet < NUR_BULLET; nCntBullet++)
//	{
//		//�e�N�X�`���̔j��
//		if (g_pTextureBullet[nCntBullet] != NULL)
//		{
//			g_pTextureBullet[nCntBullet]->Release();
//			g_pTextureBullet[nCntBullet] = NULL;
//		}
//
//	}
//
//	//���_�o�b�t�@�̔j��
//	if (g_pVtxBuffBullet != NULL)
//	{
//		g_pVtxBuffBullet->Release();
//		g_pVtxBuffBullet = NULL;
//	}
//
//}
//
////==================
////�X�V����
////==================
//void UpdateBullet(void)
//{
//	int nCntBullet;
//	//�G���W���V�X�e��
//	coleff2 += 0.1f;
//	if (coleff2 >= 1.0f)
//	{
//		coleff2 = 0.0f;
//	}
//	//�_�ŃV�X�e��
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
//	VERTEX_2D*pVtx; //���_�ւ̃|�C���^
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
//			//�G�l�~�[�̃f�[�^�擾
//			Enemy *pEnemy;
//			int nCntEnemy;
//			pEnemy = GetEnemy();
//
//			//�{�X�̃f�[�^�擾
//			Boss *pBoss;
//			pBoss = GetBoss();
//
//			//�v���C���[�̃f�[�^�擾
//			Player *nPlaye;
//			nPlaye = GetPlayer();
//
//			//�t�F�[�h�f�[�^�擾
//			FADE pFade;
//			pFade = GetFade();
//
//			//�ʒu�X�V
//			g_aBullet[nCntBullet].pos += g_aBullet[nCntBullet].move;
//
//			//���_���W
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
//					{//�G���g�p����Ă�
//						if (g_aBullet[nCntBullet].nType == 0)
//						{
//							if (((g_aBullet[nCntBullet].pos.y) <= (pEnemy->pos.y + MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.y) >= (pEnemy->pos.y - MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.x) <= (pEnemy->pos.x + MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.x) >= (pEnemy->pos.x - MAX_SIZ)))
//							{//�G���g�p����Ă铖���蔻��
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
//							{//�G���g�p����Ă铖���蔻��
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
//							{//�G���g�p����Ă铖���蔻��
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
//							{//�G���g�p����Ă铖���蔻��
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
//					{//�G���g�p����Ă�
//						if (g_aBullet[nCntBullet].nType == 0)
//						{
//							if (((g_aBullet[nCntBullet].pos.y) <= (pEnemy->pos.y + MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.y) >= (pEnemy->pos.y - MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.x) <= (pEnemy->pos.x + MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.x) >= (pEnemy->pos.x - MAX_SIZ)))
//							{//�G���g�p����Ă铖���蔻��
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
//							{//�G���g�p����Ă铖���蔻��
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
//							{//�G���g�p����Ă铖���蔻��
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
//							{//�G���g�p����Ă铖���蔻��
//								HitEnemy(nCntEnemy, 2);
//
//								g_aBullet[nCntBullet].bUse = false;
//							}
//						}
//					}
//					//--------------------------------------------------
//					if (pEnemy->nType == 2)
//					{//�G���g�p����Ă�
//						if (g_aBullet[nCntBullet].nType == 0)
//						{
//							if (((g_aBullet[nCntBullet].pos.y) <= (pEnemy->pos.y + MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.y) >= (pEnemy->pos.y - MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.x) <= (pEnemy->pos.x + MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.x) >= (pEnemy->pos.x - MAX_SIZ)))
//							{//�G���g�p����Ă铖���蔻��
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
//							{//�G���g�p����Ă铖���蔻��
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
//							{//�G���g�p����Ă铖���蔻��
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
//							{//�G���g�p����Ă铖���蔻��
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
//					{//�G���g�p����Ă�
//						if (g_aBullet[nCntBullet].nType == 0)
//						{
//							if (((g_aBullet[nCntBullet].pos.y) <= (pEnemy->pos.y + MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.y) >= (pEnemy->pos.y - MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.x) <= (pEnemy->pos.x + MAX_SIZ) &&
//								(g_aBullet[nCntBullet].pos.x) >= (pEnemy->pos.x - MAX_SIZ)))
//							{//�G���g�p����Ă铖���蔻��
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
//							{//�G���g�p����Ă铖���蔻��
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
//							{//�G���g�p����Ă铖���蔻��
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
//							{//�G���g�p����Ă铖���蔻��
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
//			//�v���C���[�̓����蔻��
//			if (g_aBullet[nCntBullet].nType == 4 && nPlaye->bUse == true)
//			{
//				if (((g_aBullet[nCntBullet].pos.y) <= (nPlaye->pos.y + 50.0f) &&
//					(g_aBullet[nCntBullet].pos.y) >= (nPlaye->pos.y - 50.0f) &&
//					(g_aBullet[nCntBullet].pos.x) <= (nPlaye->pos.x + 50.0f) &&
//					(g_aBullet[nCntBullet].pos.x) >= (nPlaye->pos.x - 50.0f)))
//				{//�G���g�p����Ă铖���蔻��
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
//					{//�G���g�p����Ă铖���蔻��
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
//					{//�G���g�p����Ă铖���蔻��
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
//					{//�G���g�p����Ă铖���蔻��
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
//					{//�G���g�p����Ă铖���蔻��
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
//					{//�G���g�p����Ă铖���蔻��
//						HitBoss(0);
//
//						g_aBullet[nCntBullet].bUse = false;
//					}
//				}
//			}
//			else if (pBoss->bUse == true && pBoss->bLife2 == true && pBoss->Inboss == true)
//			{//�G���g�p����Ă�
//				if (g_aBullet[nCntBullet].nType == 0)
//				{
//					if (((g_aBullet[nCntBullet].pos.y) <= (pBoss->pos.y + MAX_BOSSSIZ) &&
//						(g_aBullet[nCntBullet].pos.y) >= (pBoss->pos.y - MAX_BOSSSIZ) &&
//						(g_aBullet[nCntBullet].pos.x) <= (pBoss->pos.x + MAX_BOSSSIZ) &&
//						(g_aBullet[nCntBullet].pos.x) >= (pBoss->pos.x - MAX_BOSSSIZ)))
//					{//�G���g�p����Ă铖���蔻��
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
//					{//�G���g�p����Ă铖���蔻��
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
//					{//�G���g�p����Ă铖���蔻��
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
//					{//�G���g�p����Ă铖���蔻��
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
//					{//�G���g�p����Ă铖���蔻��
//						HitBoss(10);
//
//						g_aBullet[nCntBullet].bUse = false;
//					}
//				}
//			}
//		}
//		pVtx += 4;//���_�|�C���g���l�i��
//	}
//	//���_�o�b�t�@���A�����b�N
//	g_pVtxBuffBullet->Unlock();
//}
//
////==================
////�e�̕`�揈��
////==================
//void DrawBullet(void)
//{
//	LPDIRECT3DDEVICE9 pDevice;//�f�o�C�X�̃|�C���^
//	int nCntBullet;
//
//	pDevice = GetDevice();		//���
//
//								//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
//	pDevice->SetStreamSource(0, g_pVtxBuffBullet, 0, sizeof(VERTEX_2D));
//
//	//���_�t�H�[�}�b�g�̐ݒ�
//	pDevice->SetFVF(FVF_VERTEX_2D);
//
//	for (nCntBullet = 0; nCntBullet < MAX_BULLET; nCntBullet++)
//	{
//		//�e�N�X�`���̐ݒ�
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
////�e�̐ݒ�
////==================
//void SetBullet(D3DXVECTOR3 pos, D3DXVECTOR3 move, int nLife, int nType, float fSiz)
//{
//	int nCntBullet;
//	VERTEX_2D*pVtx; //���_�ւ̃|�C���^
//
//					//���b�N
//	g_pVtxBuffBullet->Lock(0, 0, (void**)&pVtx, 0);
//
//	for (nCntBullet = 0; nCntBullet <MAX_BULLET; nCntBullet++)
//	{
//		if (g_aBullet[nCntBullet].bUse == false)
//		{
//			//�e���g�p����ĂȂ��ꍇ
//			g_aBullet[nCntBullet].pos.x = pos.x;
//			g_aBullet[nCntBullet].pos.y = pos.y;
//			g_aBullet[nCntBullet].pos.z = pos.z;
//
//			g_aBullet[nCntBullet].fSiz = fSiz;
//			//���_���W
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
//	//���_�o�b�t�@���A�����b�N
//	g_pVtxBuffBullet->Unlock();
//}
