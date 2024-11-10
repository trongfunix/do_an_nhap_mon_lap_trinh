#include <stdio.h>
#include <string.h>


/*
* THE DOC GIA
*/

// Ham in danh sach doc gia
void DS_Docgia(
	int CMND[1000],
	int ma_doc_gia[1000],
	int ngay_sinh[1000],
	int Ngay[1000],
	int Thang[1000],
	int Nam_Batdau[1000],
	int Nam_Ketthuc[1000],
	char Name[100][100],
	char GT[100][100],
	char mail[100][100],
	char DC[100][100],
	int size_ma_dg)
{
	// Dung vong lap for de lap qua tung thanh phan trong tung mang, sau do xuat ra voi lenh printf
	for (int i = 0; i < size_ma_dg; i++) { // Lap qua theo thu tu cac phan tu trong mang doc_gia
		printf("\nDS doc gia %d\n", i + 1);//  sau do in ra cac phan tu cac mang con lai theo thu tu tuong ung
		printf("CMND: %d\n", CMND[i]);
		printf("ma dg: %d\n", ma_doc_gia[i]);
		printf("NS: %d\n", ngay_sinh[i]);
		printf("Ho ten: %s\n", Name[i]);
		printf("Gioi tinh: %s\n", GT[i]);
		printf("Email: %s\n", mail[i]);
		printf("Dia chi: %s\n", DC[i]);
		printf("Ngay lap the: %d/ %d/ %d\n", Ngay[i], Thang[i], Nam_Batdau[i]);
		printf("Ngay het han the: %d/ %d/ %d\n", Ngay[i], Thang[i], Nam_Ketthuc[i]);
	}
}

// Ham chinh sua thong tin doc gia
void Chinh_sua_TT(char Name[100][100], int size_ten_dg) {
	char sua_ten[100][100];
	char ten_moi[100][100];
	printf("Nhap ho ten doc gia can sua: ");
	getchar(); // loai bo ky tu xuong dong
	fgets(sua_ten[0], sizeof(sua_ten), stdin);
	// tim vi tri ten can sua trong mang, sau do nhap ten moi va dung lenh strcpy de them ten moi vao mang Name
	for (int i = 0; i < size_ten_dg; i++) {// lap qua mang Name (ten doc gia)

		if (strcmp(Name[i + 1], "tu")) { // tim vi tri ten trong mang phu hop voi ten can sua
			printf("Nhap ten moi: ");
			fgets(ten_moi[0], sizeof(ten_moi), stdin);// Nhan gia tri duoc nhap
			strcpy_s(Name[i], ten_moi[0]); // sao chep ten vua nhap vao mang ten_moi
			break;
		}

	}
}

//Ham xoa thong tin doc gia
void Xoa_TT(int CMND[1000],
	int ma_doc_gia[1000],
	int ngay_sinh[1000],
	int Ngay[1000],
	int Thang[1000],
	int Nam_Batdau[1000],
	int Nam_Ketthuc[1000],
	char Name[100][100],
	char GT[100][100],
	char mail[100][100],
	char DC[100][100], int size_ma_dg) {
	int ma_dg;
	printf("Nhap ma doc gia muon xoa: ");
	scanf_s("%d", &ma_dg);
	// Tim vi tri ma doc gia trong mang, sau do gan gia tri 0 hoac bo trong vi tri do trong cac mang con lai cua doc gia
	for (int i = 0; i < size_ma_dg; i++) { //lap qua mang ma doc gia
		if (ma_doc_gia[i] == ma_dg) //tim vi tri ma doc gia trong mang phu hop voi ten can sua
			CMND[i] = 0; // gan gia tri 0 hoac bo trong vi tri tuong ung trong cac mang thong tin doc gia con lai
		ngay_sinh[i] = 0;
		strcpy_s(Name[i], " ");
		strcpy_s(GT[i], " ");
		strcpy_s(mail[i], " ");
		strcpy_s(DC[i], " ");
		Ngay[i] = 0;
		Thang[i] = 0;
		Nam_Batdau[i] = 0;
		Nam_Ketthuc[i] = 0;
	}

}

// Ham  tim ten dua vao CMND
void Tim_kiem_CMND(int CMND[1000], char name[100][100], int size_CMND)
{
	// tim vi tri cua gia tri cmnd trong mang, sau do in ra ten tuong ung trong mang ten
	int cmt;
	printf("Nhap cmnd: ");
	scanf_s("%d", &cmt);
	for (int i = 0; i < size_CMND; i++) { // lap qua mang CMND, tim vi tri cua gia tri phu hop voi bien 'cmt' vua nhap
		if (CMND[i] == cmt)
			printf("Ten cua ban la: %s\n", name[i]); // In ra ten tuong ung  
	}

}

// Ham tim sach theo ho ten
void Tim_sach_TheoHoTen(int CMND[100], char Name[100][100], int size_ten_dg, char Ten_sach[100][100])
{
	// tim vi tri cua gia tri ten trong mang, sau do tim sach tuong ung vi tri do 
	char ten[100]; // mang ten de tam luu  tru gia tri nhap vao
	printf("Nhap ho ten: ");
	getchar();
	fgets(ten, sizeof(ten), stdin);
	ten[strcspn(ten, "\n")] = '\0'; // loai bo khoang trong tao boi fget
	for (int i = 0; i < size_ten_dg; i++) {// lap mang ten doc gia va tim vi tri ten trong mang phu hop voi ten can sua
		if (strcmp(Name[i], ten) == 0)// tim vi tri ten trong mang phu hop voi ten can sua 
			printf("Sach ban tim la: %s", Ten_sach[i]);// xuat ten sach tuong ung 
	}

}


//Nhap TT doc gia
int The_doc_gia(int CMND[1000],
	int ma_doc_gia[1000],
	int ngay_sinh[1000],
	int Ngay[1000],
	int Thang[1000],
	int Nam_Batdau[1000],
	int Nam_Ketthuc[1000],
	char Name[100][100],
	char GT[100][100],
	char mail[100][100],
	char DC[100][100],
	char Ten_sach[100][100],
	int size_ma_dg, int size_ten_dg, int size_CMND)
{ // quan ly cac de muc va goi cac ham chuc nang
	int cmnd, Ngay_sinh, Ma_DG, ngay, thang, nam, CHON, n = 0, index = 0;
	while (n < 1) {
		printf("\n -------------------------------------\n");
		printf("Vui long chon 1 trong nhung muc sau:\n1.Xem danh sach doc gia\n2.Them doc gia\n3.Chinh sua thong tin doc gia\n4.Xoa doc gia\n5.Tim kiem doc gia theo CMND\n6.Tim sach theo ho ten\n");
		printf("Ban chon: ");
		scanf_s("%d", &CHON);
		
		if (CHON == 2)//Them doc gia 
		{
			//Ma doc gia
			Ma_DG = index;
			ma_doc_gia[index] = Ma_DG;

			// Nhap CMND
			printf("Nhap CMND: ");
			scanf_s("%d", &cmnd);
			CMND[index] = cmnd;

			// Nhap ngay sinh
			printf("Nhap ngay sinh (VD: 01012002): ");
			scanf_s("%d", &Ngay_sinh);
			ngay_sinh[index] = Ngay_sinh;

			//Nhap ten
			getchar(); // loai bo ky tu xuong hang
			printf("Nhap ho ten %d: ", index);
			fgets(Name[index], sizeof(Name[index]), stdin);

			//nhap gioi tinh
			printf("Nhap gioi tinh %d: ", index);
			fgets(GT[index], sizeof(GT[index]), stdin);

			//Nhap Email
			printf("Nhap Email: ");
			fgets(mail[index], sizeof(mail[index]), stdin);

			//nhap Dia chi
			printf("Nhap dia chi: ");
			fgets(DC[index], sizeof(DC[index]), stdin);

			//Nhap ngay lap the, tinh ngay het han the
			printf("Nhap ngay lap the:");
			scanf_s("%d / %d / %d", &ngay, &thang, &nam);
			Ngay[index] = ngay;
			Thang[index] = thang;
			Nam_Batdau[index] = nam;
			Nam_Ketthuc[index] = nam + 4;
			index = index + 1;

		}

		else if (CHON == 1) // Goi ham Danh sach doc gia
			DS_Docgia(CMND, ma_doc_gia, ngay_sinh, Ngay, Thang, Nam_Batdau, Nam_Ketthuc, Name, GT, mail, DC, size_ma_dg);
		else if (CHON == 3) // Goi ham Chinh sua thong tin doc gia
			Chinh_sua_TT(Name, size_ten_dg);
		else if (CHON == 4) // Goi ham Xoa thong tin doc gia
		{
			Xoa_TT(CMND, ma_doc_gia, ngay_sinh, Ngay, Thang, Nam_Batdau, Nam_Ketthuc, Name, GT, mail, DC, size_ma_dg);

		}
		else if (CHON == 5) // Goi ham tim kiem doc gia theo cmnd
			Tim_kiem_CMND(CMND, Name, size_CMND);
		else if (CHON == 6) // Goi ham tim sach theo ten doc gia
			Tim_sach_TheoHoTen(CMND, Name, size_ten_dg, Ten_sach);
		else
			break; 

	}

	return 0;
}


// THE QUAN LI SACH

// Ham in danh sach sach trong thu vien
int DS_sach(
	int ISBN[100],
	int Nam_XB[100],
	int So_quyen[100],
	int Gia_sach[100],
	char Ten_sach[100][100],
	char Nha_XB[100][100],
	char Tac_gia[100][100],
	char The_loai[100][100], int size_ISBN)
{ 
	// tim vi tri ISBN, sau do in ra cac phan tu tuong ung trong cac mang con lai
	for (int i = 0; i < size_ISBN; i++) { //Lap qua so phan tu trong mang ISBN
		printf("\nDS sach trong thu vien %d\n", i + 1); // Sau do in ra cac phan tu tuong ung trong cac mang con lai
		printf("ISBN: %d\n", ISBN[i]);
		printf("Nam xuat ban: %d\n", Nam_XB[i]);
		printf("So quyen sach: %d\n", So_quyen[i]);
		printf("Gia sach: %d\n", Gia_sach[i]);
		printf("Ten sach: %s\n", Ten_sach[i]);
		printf("Nha xuat ban: %s\n", Nha_XB[i]);
		printf("Tac gia: %s\n", Tac_gia[i]);
		printf("The loai: %s\n", The_loai[i]);

	}
	return 0;
}

// Ham xoa thong tin sach
void Xoa_TT_sach(int ISBN[100],
	int Nam_XB[100],
	int So_quyen[100],
	int Gia_sach[100],
	char Ten_sach[100][100],
	char Nha_XB[100][100],
	char Tac_gia[100][100],
	char The_loai[100][100], int size_ISBN) 
{

	// tim vi tri ISBn sau do gan gia tri khong hoac bo trong cac phan tu tuong tung trong cac mang con lai
	int ma_sach;
	printf("Nhap ma doc gia muon xoa: ");
	scanf_s("%d", &ma_sach);

	for (int i = 0; i < size_ISBN; i++) 
	{  
		// Lap qua so phan tu trong mang ISBN
		if (ISBN[i] == ma_sach) // Neu tim thay phan tu tuong ung voi gia tri bien "ma sach", 
			//dua cac phan tu tuong ung trong cac mang con lai ve 0 hoac bo trong
		{
			ISBN[i] = 0;
			Nam_XB[i] = 0;
			So_quyen[i] = 0;
			Gia_sach[i] = 0;
			strcpy_s(Ten_sach[i], " ");
			strcpy_s(Nha_XB[i], " ");
			strcpy_s(Tac_gia[i], " ");
			strcpy_s(The_loai[i], " ");
		}

	}

}

// Ham sua thong tin sach
void Sua_TT_sach(char Ten_sach[100][100], int size_Ten_sach)
{
	// tim vi tri ten sach trong mang sau do, them ten moi dung ham strcpy 
	char sua_ten[100][100];
	char ten_moi[100][100];
	int n = 0;
	printf("Nhap ten sach can sua: ");
	getchar();
	fgets(sua_ten[0], sizeof(sua_ten), stdin);
	for (int i = 0; i < size_Ten_sach; i++) { //Lap qua so phan tu trong mang Ten sach

		if (strcmp(Ten_sach[i + 1], sua_ten[0])) { // so sanh phan tu trong voi gia tri vua duoc nhap
			printf("Nhap ten moi: %s ", Ten_sach[i]); // nhap ten moi
			fgets(ten_moi[0], sizeof(ten_moi), stdin);
			strcpy_s(Ten_sach[i], ten_moi[n]); // dung ham strcpy_s de copy gia tri moi nhap vao mang ten_moi
			n = n + 1;
			break;
		}

	}
}

// Ham tim ten sach bang ma ISBN
void Tim_kiem_ISBN(int ISBN[1000], char Ten_sach[100][100], int size_ISBN)
{
	int ma_sach;
	printf("tim cmnd: ");
	scanf_s("%d", &ma_sach);
	for (int i = 0; i < size_ISBN; i++) { //Lap qua so phan tu trong mang ISBN
		if (ISBN[i] == ma_sach) // Tim vi tri phan tu trong mang trung voi ma sach vua nhap
			printf("%s\n", Ten_sach[i]); //  Xuat ten sach tuong ung
	}

}

// Ham tin sach theo ten
void Tim_sach_Theoten(int ISBN[100],
	int Nam_XB[100],
	int So_quyen[100],
	int Gia_sach[100],
	char Ten_sach[100][100],
	char Nha_XB[100][100],
	char Tac_gia[100][100],
	char The_loai[100][100], int size_Ten_sach)
{
	char ten[100];
	printf("Nhap ten sach: ");
	fgets(ten, sizeof(ten), stdin);
	for (int i = 0; i < size_Ten_sach; i++) { // Lap qua so phan tu trong mang ten sach
		if (strcmp(Ten_sach[i], ten) == 0) // tim vi tri phan tu trong mang tuong ung voi ten vua duoc nhap
		{
			printf("ISBN: %d\n", ISBN[i]); // xuat ra cac phan tu tuong ung trong cac mang con lai
			printf("Nam xuat ban: %d\n", Nam_XB[i]);
			printf("So quyen sach: %d\n", So_quyen[i]);
			printf("Gia sach: %d\n", Gia_sach[i]);
			printf("Ten sach: %s\n", Ten_sach[i]);
			printf("Nha xuat ban: %s\n", Nha_XB[i]);
			printf("Tac gia: %s\n", Tac_gia[i]);
			printf("The loai: %s\n", The_loai[i]);
		}

	}
}

// ham the quan ly sach
int The_sach(int ISBN[100],
	int Nam_XB[100],
	int So_quyen[100],
	int Gia_sach[100],
	char Ten_sach[100][100],
	char Nha_XB[100][100],
	char Tac_gia[100][100],
	char The_loai[100][100], int size_ISBN, int size_Ten_sach)
{// quan ly de muc va goi ham chuc nang
	int ma_sach, nam_xb, gia, so_sach, CHON, n = 0, index = 0;

	while (n < 1) {
		// xuat ra cac tinh nang co the lua chon 
		printf("\n -------------------------------------\n");
		printf("Vui long chon 1 trong nhung muc sau:\n1.Xem danh sach sach trong thu vien\n2.Them sach\n3.Chinh sua thong tin sach\n4.Xoa thong tin sach\n5.Tim kiem sach theo ISBN\n6.Tim sach theo ten sach\n");
		printf("Ban chon: ");
		scanf_s("%d", &CHON);

		if (CHON == 2)//Them sach
		{
			//Ma sach
			ma_sach = index;
			ISBN[index] = ma_sach;
			// Nhap nam xuat ban
			printf("Nhap nam xuat ban: ");
			scanf_s("%d", &nam_xb);
			Nam_XB[index] = nam_xb;
			// Nhap gia sach
			printf("Nhap gia sach: ");
			scanf_s("%d", &gia);
			Gia_sach[index] = gia;
			//Nhap so quyen sach
			printf("Nhap so sach: ");
			scanf_s("%d", &so_sach);
			So_quyen[index] = so_sach;
			// Nhap ten sach
			getchar();
			printf("Nhap ten sach : ");
			fgets(Ten_sach[index], sizeof(Ten_sach[index]), stdin);
			//nhap nha xuat ban
			printf("Nhap nha xuat ban: ");
			fgets(Nha_XB[index], sizeof(Nha_XB[index]), stdin);
			//Nhap tac gia
			printf("Nhap ten tac gia: ");
			fgets(Tac_gia[index], sizeof(Tac_gia[index]), stdin);
			//nhap the loai
			printf("Nhap the loai: ");
			fgets(The_loai[index], sizeof(The_loai[index]), stdin);
		}

		else if (CHON == 1) { // Goi ham danh sach sach trong thu vien)
			DS_sach(ISBN, Nam_XB, So_quyen, Gia_sach, Ten_sach, Nha_XB, Tac_gia, The_loai, size_ISBN);
		}
		else if (CHON == 3) { // GOi ham sua thong tin sach
			Sua_TT_sach(Ten_sach, size_Ten_sach);

		}
		else if (CHON == 4)
		{// GOi ham xoa thong tin sach
			Xoa_TT_sach(ISBN, Nam_XB, So_quyen, Gia_sach, Ten_sach, Nha_XB, Tac_gia, The_loai, size_ISBN);
		}
		else if (CHON == 5) {// Goi ham tim sach bang ISBN
			Tim_kiem_ISBN(ISBN, Ten_sach, size_ISBN);
		}
		else if (CHON == 6) { // GOi ham tim sach theo ten
			Tim_sach_Theoten(ISBN, Nam_XB, So_quyen, Gia_sach, Ten_sach, Nha_XB, Tac_gia, The_loai, size_Ten_sach);
		}
		else { break; }
	}
	return 0;
}

// Phieu muon sach
void Phieu_muon(int ma_doc_gia[100], int ISBN[100], int ngay_muon[100], int thang_muon[100], int nam_muon[100],
	int ngay_tra_du_kien[100], int thang_tra_du_kien[100], int nam_tra_du_kien[100], int Doc_gia_muon[100], int Sach_muon[100], int size_ma_dg)
{

	int ma_dg, ma_sach, ngay, thang, nam, ngay_dukien, thang_dukien, nam_dukien;
	int index = 0;


	printf("Nhap ma doc gia cua ban: ");
	scanf_s("%d", &ma_dg);
	printf("Nhap ISBN sach ban muon muon: ");
	scanf_s("%d", &ma_sach);
	printf("Nhap ngay muon sach (VD:1/1/2024) : ");
	scanf_s("%d/%d/%d", &ngay, &thang, &nam);
	printf("Nhap ngay tra sach du kien (7 ngay ke tu ngay muon sach): ");
	scanf_s("%d/%d/%d", &ngay_dukien, &thang_dukien, &nam_dukien);


	for (int i = 0; i < size_ma_dg; i++) // lap qua so phan tu cua mang ma doc gia
	{

		if (ma_dg == ma_doc_gia[i] && ma_sach == ISBN[i]) { // trong truong hop ma doc gia v� ma sach tuong ung voi gia tri nhap vao
			Doc_gia_muon[index] = ma_dg; // them gia tri moi nhap vao cac mang da tao voi thu tu la index
			Sach_muon[index] = ma_sach;
			//them ngay muon vao mang
			ngay_muon[index] = ngay;
			thang_muon[index] = thang;
			nam_muon[index] = nam;
			//them ngay tra du kien vao mang
			ngay_tra_du_kien[index] = ngay_dukien;
			thang_tra_du_kien[index] = thang_dukien;
			nam_tra_du_kien[index] = nam_dukien;
			index = index + 1;  // tang index len 1
		}

	}

}

int So_ngay_trong_thang(int nam, int thang) {
	switch (thang) {
	case 2:
		if ((nam % 4 == 0) || (nam % 400 == 0))  // nam nhuan se chia het cho 4 hoac 400
			return 29; // tra ve gia tri thang 2 la 29 ngay
		else
		{
			return 28; // nguoc lai se tra gia tri 28 ngay
		}
	case 4:
	case 6:
	case 9:
	case 11:
		return 30; // cac truong hop thang 4,6,9,11 tra gia tri 30 ngay
	default:
		return 31; // 31 ngay la mac dinh
	}

}

int bo_dem_ngay(int nam, int thang, int ngay) { // nhan gia tri nam/thang/ngay, quy doi chung ra "ngay" de cong don lai
	int so_ngay = 0;
	// dung nam hien tai, de tinh tong so ngay ke tu moc 1970
	for (int i = 1970; i < nam; i++) {  // lay i bat dau tu nam 1970, so nam tang len 1 khi i nho hon bien "nam"
		if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) // neu i la nam nhuan thi cong 366 ngay vao bien so_ngay
			so_ngay = so_ngay + 366;
		else { so_ngay = so_ngay + 365; }// neu la nam khong nhuan thi chi cong 365
	}

	for (int k = 1; k < thang; k++) { // con don so ngay voi tong so ngay cua cac thang
		so_ngay = so_ngay + So_ngay_trong_thang(nam, k);
	}
	so_ngay = +ngay; // tiep tuc cong don voi so ngay hien tai
	return so_ngay;
}

void Phieu_tra_sach(int Doc_gia_muon[100], int Sach_muon[100], int Gia_sach[100], int ISBN[100],
	int ngay_tra_du_kien[100], int thang_tra_du_kien[100], int nam_tra_du_kien[100], int size_dg_muon, int size_sach_muon, int size_ISBN, int doc_gia_tre_han[100]) {
	int chon;
	int ma_dg, ma_sach, ngay_tra, thang_tra, nam_tra, tien_phat, boi_thuong;
	int index = 0, n = 0, m = 0;
	int doc_gia_mat_sach[100];
	int sach_mat[100];
	int sach_tra[100];

	printf("Chon 1 trong cac muc sau: \n1. Tra sach\n2. Mat sach");
	printf("\nBan chon: ");
	scanf_s("%d", &chon);
	if (chon == 1) {
		printf("Nhap ma doc gia cua ban: "); // nhap cac gia tri tuong ung: ma doc gia, ma sach, ngay thang nam tra sach
		scanf_s("%d", &ma_dg);
		printf("Nhap ISBN sach ban muon tra: ");
		scanf_s("%d", &ma_sach);
		printf("Nhap ngay tra sach: ");
		scanf_s("%d/%d/%d", &ngay_tra, &thang_tra, &nam_tra);
		for (int i = 0; i < size_dg_muon; i++) { // lap qua mang doc gia da muon sach
			if (ma_dg == Doc_gia_muon[i]) { // gia tri nhap vao thoa phan tu trong mang  
				int ngay_tra_sach = bo_dem_ngay(nam_tra, thang_tra, ngay_tra); // cong don tong so ngay tinh den ngay tra sach
				int han_tra_sach = bo_dem_ngay(nam_tra_du_kien[i], thang_tra_du_kien[i], ngay_tra_du_kien[i]);// cong don tong so ngay tinh den ngay tra du kien
				if (ngay_tra_sach > han_tra_sach) {  //neu tong so ngay cua bien tra sach nho hon bien ngay tra du kien
					doc_gia_tre_han[index] = ma_dg; // them doc gia vao mang doc gia tre han theo thu tu index
					index = index + 1; // tang index len 1
					tien_phat = (ngay_tra_sach - han_tra_sach) * 5000; // tinh tien phat dua tren so ngay tre, moi ngay 5000

					printf("Tien phat cua ban la %d\n", tien_phat);
				}
				else {
					sach_tra[n] = ma_sach; // them sach da duoc tra vao mang sach_tra theo thu tu n
					n = n + 1; // tang n len 1
				}
			}
		}

	}
	if (chon == 2) { // truong h�p mat sach
		printf("Nhap ma doc gia cua ban: ");
		scanf_s("%d", &ma_dg);
		printf("Nhap ISBN sach ban lam mat: ");
		scanf_s("%d", &ma_sach);
		for (int i = 0; i < size_sach_muon; i++) { // lap qua so phan tu trong bien sach_muom
			if (ma_sach == Sach_muon[i]) { // neu gia tri nhap vao phu hop voi phan tu trong mang:
				sach_mat[m] = ma_sach;  // them chung vao mang "sach_mat" va "doc gia mat sach" theo thu tu m
				doc_gia_mat_sach[m] = ma_dg;
				m = m + 1; // tang m len 1
				for (int k = 0; k < size_ISBN; k++) { // tim vi tri ma sach va gia sach tuong ung 
					if (ma_sach == ISBN[k]) {
						boi_thuong = Gia_sach[k] * 2; // tinh tien boi thuong = gia sach * 2
						printf("%d\n", boi_thuong);
					}

				}
			}
		}
	}
}

// Thong ke
void Thong_ke_tv(int ISBN[100], int ma_doc_gia[100], char GT[100][100], int Sach_muon[100], int doc_gia_tre_han[100],
	int size_ISBN, int size_GT, int size_ma_dg, int size_sach_muon, int size_dg_tre_han, int size_the_loai, char The_loai[100][100]) {

	int GT_nam = 0, GT_nu = 0;


	printf("Tong so sach trong thu vien l� %d\n", size_ISBN); // thong ke tong so sach dua tren tong so ma ISBN
	printf("Tong so doc gia cua thu vien l� %d\n", size_ma_dg); // thong ke tong so doc gia dua tren tong so ma doc gia
	int so_sach_theo_the_loai[100]; // mang luu tru so luong trung lap cua tung phan tu tuong ung voi cac phan tu trong mang "the loai"
	memset(so_sach_theo_the_loai, 0, sizeof(so_sach_theo_the_loai));	// cho cac phan tu trong mang ve = 0

	for (int i = 0; i < size_the_loai; i++) { // lap qua mang the loai
		for (int j = i + 1; j < size_the_loai; j++) { // o moi lan lap, lap tiep tu phan tu i+1 de tim so the loai giong nhau
			if (strcmp(The_loai[i], The_loai[j]) == 0) {// neu tim thay cac cac phan tu the loai giong nhau
				so_sach_theo_the_loai[i]++; // tang phan tu o vi tri i va j len 1
				so_sach_theo_the_loai[j]++;
			}
		}
	}

	printf("So sach theo tung the loai: \n");
	for (int i = 0; i < size_the_loai; i++) { // lap qua mang "the_loai", in ra ten the loai va so luong tuong ung
		if (so_sach_theo_the_loai[i] + 1 > 0) { // cong 1 cho truong hop mang chi co 1 phan tu, khong kich hoat duoc dieu kien phia tren
			printf("%s: %d\n", The_loai[i], so_sach_theo_the_loai[i] + 1); // phai cong them 1, do bat dau dem tu so 0 
			so_sach_theo_the_loai[i] = 0;
		}
	}
	// tim so gioi tinh nam va nua trong tong so doc gia
	for (int n = 0; n <= size_GT; n++) // lap qua mang gioi tinh
	{
		if (strcmp(GT[n], "Nam") == 0 || strcmp(GT[n], "nam") == 0) // moi khi tim thay phan tu "nam", tang bien GT_nam len 1
		{
			GT_nam = GT_nam + 1;
		}
		else if (strcmp(GT[n], "Nu") == 0 || strcmp(GT[n], "nu") == 0) // Nguoc lai neu l� "nu" thi tang bien GT_nu len 1
		{
			GT_nu = GT_nu + 1;
		}
	}
	printf("Tong so doc gia nam cua thu vien l� %d\n", GT_nam); // xuat ra so gioi tinh nam va nu
	printf("Tong so doc gia nu cua thu vien l� %d\n", GT_nu);
	printf("Tong so sach dang duoc muon trong thu vien l� %d\n", size_sach_muon);// thong ke tong so sach dang duoc muon
	printf("Tong so doc gia tre han cua thu vien l� %d\n", size_dg_tre_han);// thong ke tong so doc gia tre han
}

int main(void) {
	// Cac mang cua the doc gia
	int CMND[] = { 272113355 };
	int ma_doc_gia[] = { 0 };
	int ngay_sinh[] = { 01012003 };
	int Ngay[] = { 1 };
	int Thang[] = { 1 };
	int Nam_Batdau[] = { 2022 };
	int Nam_Ketthuc[] = { 2026 };
	char Name[][100] = { "Nguyen Van A" };
	char GT[][100] = { "Nam", "Nu" };
	char mail[][100] = { " a123@gmail.com" };
	char DC[][100] = { " 11/22, ha noi" };

	// Cac mang cua the sach
	int ISBN[] = { 0 };
	int Nam_XB[] = { 1984 };
	int So_quyen[] = { 2 };
	int Gia_sach[] = { 100000 };
	char Ten_sach[100][100] = { "Thep da toi the day" };
	char Nha_XB[100][100] = { " vo danh " };
	char Tac_gia[100][100] = { "Nikolai Alekseyevich Ostrovsky" };
	char The_loai[][100] = { "Tieu thuyet" };

	// cac mang cua the muon sach
	int ngay_muon[] = { 21 };
	int thang_muon[] = { 9 };
	int nam_muon[] = { 2023 };
	int ngay_tra_du_kien[] = { 28 };
	int thang_tra_du_kien[] = { 9 };
	int nam_tra_du_kien[] = { 2023 };
	int Doc_gia_muon[] = { 0 };
	int Sach_muon[] = { 0 };

	// Cac mang cua the tra sach
	int ngay_tra[100];

	int thang_tra[100];
	int nam_tra[100];
	int doc_gia_tre_han[] = { 0 };

	// Bien ham main
	int Chon; // lua chon de muc cua nguoi dung
	// so phan tu trong mang cua cac mang tren
	int size_dg_muon = sizeof(Doc_gia_muon) / sizeof(Doc_gia_muon[0]);
	int size_the_loai = sizeof(The_loai) / sizeof(The_loai[0]);
	int size_sach_muon = sizeof(Sach_muon) / sizeof(Sach_muon[0]);
	int size_ISBN = sizeof(ISBN) / sizeof(ISBN[0]);
	int size_ma_dg = sizeof(ma_doc_gia) / sizeof(ma_doc_gia[0]);
	int size_GT = sizeof(GT) / sizeof(GT[0]);
	int size_dg_tre_han = sizeof(doc_gia_tre_han) / sizeof(doc_gia_tre_han[0]);
	int size_ten_dg = sizeof(Name) / sizeof(Name[0]);
	int size_CMND = sizeof(CMND) / sizeof(CMND[0]);
	int size_Ten_sach = sizeof(Ten_sach) / sizeof(Ten_sach[0]);

	// quan ly de muc va goi cac ham the
	while (1 > 0) {
		printf("\n -------------------------------------\n");
		printf("Chao mung den voi thu vien truong Dai hoc Khoa hoc tu nhien TP HCM! ");
		printf("\nVui long chon the ban muon su dung: ");
		printf("\n1. The doc gia\n2. The sach\n3. Lap phieu muon sach\n4. Lap phieu tra sach\n5. Thong ke thong tin thu vien\n");
		printf("Ban chon: ");
		scanf_s("%d", &Chon);

		if (Chon == 1) {
			The_doc_gia(CMND, ma_doc_gia, ngay_sinh, Ngay, Thang, Nam_Batdau, Nam_Ketthuc, Name, GT, mail, DC, Ten_sach, size_ma_dg, size_ten_dg, size_CMND);

		}
		else if (Chon == 2)
		{
			The_sach(ISBN, Nam_XB, So_quyen, Gia_sach, Ten_sach, Nha_XB, Tac_gia, The_loai, size_ISBN, size_Ten_sach);
		}
		else if (Chon == 3)
			Phieu_muon(ma_doc_gia, ISBN, ngay_muon, thang_muon, nam_muon, ngay_tra_du_kien, thang_tra_du_kien, nam_tra_du_kien, Doc_gia_muon, Sach_muon, size_ma_dg);
		else if (Chon == 4)
			Phieu_tra_sach(Doc_gia_muon, Sach_muon, Gia_sach, ISBN, ngay_tra_du_kien,
				thang_tra_du_kien, nam_tra_du_kien, size_dg_muon, size_sach_muon, size_ISBN, doc_gia_tre_han);
		else if (Chon == 5)
			Thong_ke_tv(ISBN, ma_doc_gia, GT, Sach_muon, doc_gia_tre_han, size_ISBN, size_GT, size_ma_dg, size_sach_muon,
				size_dg_tre_han, size_the_loai, The_loai);

	}

}