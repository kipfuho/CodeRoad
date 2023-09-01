#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <iomanip>

using namespace std;

int soSinhVien;

struct MonHoc {
    string maMH;
    int sotinchi;
    int sotinchiLT;
    int sotinchiBT;
    int sotinchiTH;
    int sotinchihocphi;
};

struct SinhVien {
    string mssv;
    string hoten;
    int somonhoc;
    int tientinchi;
    int hocphi;
    vector<MonHoc> monhoc;
};

int NhapDuLieuSo(){
	int temp;
	while (!(cin >> temp)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Hay dien so hop le!" << endl;
    }
    return temp;
}

string LayLoaiGio(const MonHoc& monhoc) {
    if (monhoc.sotinchiTH == 3 && monhoc.sotinchiLT == 0 && monhoc.sotinchiTH == 0) {
        return "DAMH";
    } else if (monhoc.sotinchi == 6) {
        return "DATN Cu Nhan";
    } else if (monhoc.sotinchi == 12) {
        return "DATN Ky su";
    } else {
        if (monhoc.sotinchiLT >= 1 && monhoc.sotinchiBT >= 1 && monhoc.sotinchiTH >= 1) {
            return "LT-BT-TN";
        } else if (monhoc.sotinchiLT >= 1 && monhoc.sotinchiTH >= 1) {
            return "LT-TN";
        } else if (monhoc.sotinchiLT >= 1 && monhoc.sotinchiBT >= 1) {
            return "LT-BT";
        } else {
            return "DA";
        }
    }
}

string LayKhoiLuong(const MonHoc& monhoc) {
    string khoiluong = to_string(monhoc.sotinchi);
    khoiluong += "(" + to_string(monhoc.sotinchiLT) + "-";
    khoiluong += to_string(monhoc.sotinchiTH) + "-";
    khoiluong += to_string(monhoc.sotinchiTH) + "-";
    khoiluong += to_string(monhoc.sotinchi * 2) + ")";
    return khoiluong;
}

void NhapDanhSachSinhVien(vector<SinhVien>& danhSachSinhVien) {
	cout << "Ban da chon nhap danh sach sinh vien!" << endl;

    for (int i = 0; i < soSinhVien; i++) {
        SinhVien sinhvien;
        cout << "Nhap thong tin cho hoc vien thu " << i + 1 << endl;

        cout << "	Ma so sinh vien: ";
        cin.ignore();
        getline(cin, sinhvien.mssv);

        cout << "	Ho ten sinh vien: ";
        cin.ignore();
        getline(cin, sinhvien.hoten);
        
        cout << "	So tien mot tin chi: ";
        sinhvien.tientinchi = NhapDuLieuSo();

        cout << "	So mon hoc: ";
        sinhvien.somonhoc = NhapDuLieuSo();

        cout << "	Nhap thong tin cho cac mon hoc:" << endl;
        for (int j = 0; j < sinhvien.somonhoc; j++) {
            MonHoc monhoc;
            cout << "		Nhap thong tin cho mon hoc thu " << j + 1 << endl;

            cout << "		Ma mon hoc: ";
            cin.ignore();
        	getline(cin, monhoc.maMH);

            cout << "		So tin chi: ";
            cin >> monhoc.sotinchi;

            if (monhoc.sotinchi != 6 && monhoc.sotinchi != 12) {
                cout << "		So tin chi LT: ";
                monhoc.sotinchiLT = NhapDuLieuSo();
                
                cout << "		So tin chi BT: ";
                monhoc.sotinchiBT = NhapDuLieuSo();

                cout << "		So tin chi TH: ";
                monhoc.sotinchiTH = NhapDuLieuSo();
            } else {
                monhoc.sotinchiLT = 0;
                monhoc.sotinchiBT = 0;
                monhoc.sotinchiTH = 0;
            }

            monhoc.sotinchihocphi = monhoc.sotinchiLT + monhoc.sotinchiBT + monhoc.sotinchiTH * 1.5;
            sinhvien.hocphi += sinhvien.tientinchi*monhoc.sotinchihocphi;

            sinhvien.monhoc.push_back(monhoc);
        }

        danhSachSinhVien.push_back(sinhvien);
    }
}

void InThongTinHocVien(const vector<SinhVien>& danhSachSinhVien) {
	cout << "Ban da chon xuat danh sach sinh vien!" << endl;
	
    for (const auto& sinhvien : danhSachSinhVien) {
    	cout << "_______________________________________________" << endl << endl;
    	
        cout << "	Ma so sinh vien: " << sinhvien.mssv << endl;
        cout << "	Ho ten: " << sinhvien.hoten << endl;
        cout << "	So tien 1 tin chi: " << sinhvien.tientinchi << endl;
        cout << "	Phai nop: " << sinhvien.hocphi << endl;
        cout << "	Tong tien thieu: " << sinhvien.hocphi << endl;
        cout << "	Tinh trang nop hoc phan: Con thieu" << endl;

        cout << "	Chi tiet cac mon hoc:" << endl;
        cout << setw(15) << "Ma MH" << setw(20) << "Loai gio" << setw(30) << "Khoi luong" << setw(40) << "Hoc phi phai nop" << endl;
        for (const auto& monhoc : sinhvien.monhoc) {
            cout << setw(15) << monhoc.maMH << setw(20) << LayLoaiGio(monhoc) << setw(30) << LayKhoiLuong(monhoc) 
			<< setw(40) << monhoc.sotinchihocphi * sinhvien.tientinchi << endl;
        }

        cout << endl;
    }
}

void InHeader(bool mode){
	cout << "De2_6_IT3040_2022.2" << endl;
	cout << "Nguyen Dinh Ut Biu - 20215317 - 727636" << endl;
	if(mode){
		cout << "**	  Chuong trinh quan ly hoc phi   **" << endl;
		cout << "**1. Nhap cac sinh vien va mon hoc              **" << endl;
		cout << "**2. In danh sach sinh vien va hoc phi cac mon  **" << endl;
		cout << "**3. Thoat									     **" << endl;
		cout << "**************************************" << endl;
	}
	else{
		cout << "Nhap so sinh vien: ";
		soSinhVien = NhapDuLieuSo();
	}
}

int main() {
	InHeader(false);
	system("cls");
	InHeader(true);
	
    vector<SinhVien> danhSachSinhVien;

    int choice;
    do {
        cin >> choice;
		system("cls");
		InHeader(true);
		
        switch (choice) {
            case 1:            	
                NhapDanhSachSinhVien(danhSachSinhVien);
                cout << "Ban da nhap thanh cong, bam phim bat ki de tiep tuc!" << endl;
                break;
            case 2:
                InThongTinHocVien(danhSachSinhVien);
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

