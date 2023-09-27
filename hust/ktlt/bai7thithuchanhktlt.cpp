#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <iomanip>

using namespace std;

int soCty;

struct ManhDat {
    string maSO;
    int dongia;
    int hinhdang;
    double canh1;
    double canh2;
    double canh3;
    double tiencoc;
    double dientich;
    double thanhtien;
    double giamgia;
};

struct CongTy {
    string tencty;
    string diachi;
    double dongiatrungbinh;
    double tongdientich;
    double tongthanhtien;
    double tongdatcoc;
    double tonggiamgia;
    vector<ManhDat> manhdat;
};

double NhapDuLieuSo(){
	double temp;
	while (!(cin >> temp)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Hay dien so hop le!" << endl;
    }
    return temp;
}

void NhapDanhSachCongTy(vector<CongTy>& danhSachCongTy) {
	cout << "Ban da chon nhap danh sach cong ty!" << endl;

    for (int i = 0; i < soCty; i++) {
        CongTy cty;
        cout << "Nhap thong tin cho cong ty thu " << i + 1 << endl;

        cout << "	Ten cong ty: ";
        cin.ignore();
        getline(cin, cty.tencty);

        cout << "	Dia chi: ";
        cin.ignore();
        getline(cin, cty.diachi);
        
        cout << "	So mieng dat: ";
        int soMiengDat;
        cin >> soMiengDat;
        
    	cty.dongiatrungbinh = 0;
		cty.tongdientich = 0;
		cty.tongthanhtien = 0;
		cty.tongdatcoc = 0;
		cty.tonggiamgia = 0;

        cout << "	Nhap thong tin cho cac mieng dat:" << endl;
        for (int j = 0; j < soMiengDat; j++) {
            ManhDat manhdat;
            bool check;
            cout << "		Nhap thong tin cho manh dat thu " << j + 1 << endl;

            cout << "		Ma manh dat(MD001, MD002, MD003): ";
            cin.ignore();
            do{
            	check = false;
	        	getline(cin, manhdat.maSO);
	        	if(manhdat.maSO == "MD001"){
        			manhdat.dongia = 50;
        			manhdat.tiencoc = 0.7;
	        	}
        		else if(manhdat.maSO == "MD002"){
        			manhdat.dongia = 30;
        			manhdat.tiencoc = 0.5;
	        	}
        		else if(manhdat.maSO == "MD003"){
        			manhdat.dongia = 10;
        			manhdat.tiencoc = 0.3;
	        	}
	        	else{
	        		cout << "Hay nhap ma manh dat hop le" << endl;
	        		check = true;
				}
			}
			while(check);

            cout << "		Don gia theo m^2: " << manhdat.dongia << endl;
            cout << "		Manh dat hinh(Vuong, Thang, TamGiac, HCNhat): ";
            do{
            	check = false;
            	string hinhdang; 
	        	getline(cin, hinhdang);
	        	if(hinhdang == "TamGiac"){
        			manhdat.hinhdang = 1;
        			manhdat.giamgia = 0.1;
	        	}
	        	else if(hinhdang == "Thang"){
        			manhdat.hinhdang = 2;
        			manhdat.giamgia = 0.1;
	        	}
	        	else if(hinhdang == "Vuong"){
        			manhdat.hinhdang = 3;
        			manhdat.giamgia = 0;
	        	}
        		else if(hinhdang == "HCNhat"){
        			manhdat.hinhdang = 4;
        			manhdat.giamgia = 0;
				}
	        	else{
        			cout << "		Hay nhap hinh dang hop le" << endl;
        			check = true;
				}
			}
			while(check);
            
    		if(manhdat.hinhdang == 1){
    			cout << "		Nhap chieu cao manh dat: ";
    			manhdat.canh1 = NhapDuLieuSo();
    			cout << "		Nhap canh day manh dat: ";
    			manhdat.canh2 = NhapDuLieuSo();
    			manhdat.dientich = manhdat.canh1*manhdat.canh2/2.0;
    		}
    		else if(manhdat.hinhdang == 2){
    			cout << "		Nhap day lon manh dat: ";
    			manhdat.canh1 = NhapDuLieuSo();
    			cout << "		Nhap day nho manh dat: ";
    			manhdat.canh2 = NhapDuLieuSo();
    			cout << "		Nhap chieu cao manh dat: ";
    			manhdat.canh3 = NhapDuLieuSo();
    			manhdat.dientich = (manhdat.canh1 + manhdat.canh2)*manhdat.canh3 / 2.0;
    		}
    		else if(manhdat.hinhdang == 3){
    			cout << "		Nhap canh manh dat: ";
    			manhdat.canh1 = NhapDuLieuSo();
    			manhdat.dientich = manhdat.canh1*manhdat.canh1;
    		}
    		else if(manhdat.hinhdang == 4){
    			cout << "		Nhap chieu dai manh dat: ";
    			manhdat.canh1 = NhapDuLieuSo();
    			cout << "		Nhap chieu rong manh dat: ";
    			manhdat.canh2 = NhapDuLieuSo();
    			manhdat.dientich = manhdat.canh1*manhdat.canh2;
    		}
			manhdat.thanhtien = manhdat.dientich*manhdat.dongia;
			cout << "		Dien tich: " << fixed << setprecision(1) << manhdat.dientich << endl;
			cout << "		Thanh tien: " << fixed << setprecision(1) << manhdat.thanhtien << endl;
			cout << "		Tien dat coc: " << fixed << setprecision(1) << manhdat.tiencoc*manhdat.thanhtien << endl;		
			cout << "		Giam gia: " << fixed << setprecision(1) << manhdat.giamgia*manhdat.thanhtien << endl;
			cty.dongiatrungbinh += manhdat.dongia / soMiengDat;
			cty.tongdientich += manhdat.dientich;
			cty.tongthanhtien += manhdat.thanhtien;
			cty.tongdatcoc += manhdat.thanhtien*manhdat.tiencoc;
			cty.tonggiamgia += manhdat.thanhtien*manhdat.giamgia;
			
            cty.manhdat.push_back(manhdat);
        }
		
        danhSachCongTy.push_back(cty);
    }
}

void InThongTinCongTy(const vector<CongTy>& danhSachCongTy) {
	cout << "Ban da chon xuat danh sach cong ty!" << endl;
	
    for (const auto& cty : danhSachCongTy) {
    	cout << "_______________________________________________" << endl << endl;
    	
        cout << "	Ten cong ty: " << cty.tencty << endl;
        cout << "	Dia chi: " << cty.diachi << endl;
        cout << "	So mieng dat: " << cty.manhdat.size() << endl;
        cout << "	Don gia trung binh: " << cty.dongiatrungbinh << endl;
        cout << "	Tong dien tich: " << cty.tongdientich << endl;
        cout << "	Tong thanh tien: " << cty.tongthanhtien << endl;
        cout << "	Tong dat coc: " << cty.tongdatcoc << endl;
        cout << "	Tong giam gia: " << cty.tonggiamgia << endl;

        cout << "	Chi tiet cac mon hoc:" << endl;
        cout << setw(10) << "MaMD" << setw(15) << "Hinh dang" << setw(10) << "Don gia" << setw(15) << "Dien tich" << setw(20) << "Thanh tien" << setw(15) << "Giam gia" << setw(15) << "Dat coc" << endl;
        for (const auto& manhdat : cty.manhdat) {
            cout << setw(10) << manhdat.maSO << setw(15) << manhdat.hinhdang << setw(10) << manhdat.dongia
			<< setw(15) << fixed << setprecision(1) << manhdat.dientich << setw(20) << fixed << setprecision(1) << manhdat.thanhtien 
			<< setw(15) << fixed << setprecision(1) << manhdat.giamgia*manhdat.thanhtien << setw(15) << fixed << setprecision(1) << manhdat.thanhtien*manhdat.tiencoc << endl;
        }

        cout << endl;
    }
}

void InHeader(bool mode){
	cout << "De7_IT3040_2022.2" << endl;
	cout << "Nguyen Dinh Ut Biu - 20215317 - 727636" << endl;
	if(mode){
		cout << "**	  Chuong trinh quan ly bat dong san   **" << endl;
		cout << "**1. Nhap thong tin cong ty                        **" << endl;
		cout << "**2. In danh sach cong ty va manh dat cua cong ty  **" << endl;
		cout << "**3. Thoat                                         **" << endl;
		cout << "**************************************" << endl;
	}
	else{
		cout << "Nhap so cong ty: ";
		soCty = NhapDuLieuSo();
	}
}

int main() {
	InHeader(false);
	system("cls");
	InHeader(true);
	
    vector<CongTy> danhSachCongTy;

    int choice;
    do {
        cin >> choice;
		system("cls");
		InHeader(true);
		
        switch (choice) {
            case 1:            	
                NhapDanhSachCongTy(danhSachCongTy);
                cout << "Ban da nhap thanh cong, bam phim bat ki de tiep tuc!" << endl;
                break;
            case 2:
                InThongTinCongTy(danhSachCongTy);
                cout << "Bam phim bat ki de tiep tuc!" << endl;
                break;
            case 3:
                cout << "Thoat chuong trinh..." << endl;
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai." << endl;
                break;
        }

        cout << endl;
        
    } while (choice != 3);

    return 0;
}

