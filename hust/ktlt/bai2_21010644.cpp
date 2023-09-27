// Bien dich thanh file thuc thi: g++ -o bai2_21010644.exe bai2_21010644.cpp

#include <iostream>
#include <vector>

using namespace std;

// 4 lop
class File {
protected:
    string fileName;
    string fileType;
    int fileSize;

public:
    File(string name, string type, int size) {
        fileName = name;
        fileType = type;
        fileSize = size;
    }
    
    string Type(){
    	return fileType;
	}

    virtual void open() = 0;
};

class Document : public File {
private:
	int pageCount;
	
public:
    Document(string name, int size, int pages) : File(name, "Document", size), pageCount(pages) {}

    void open() {
        cout << "fileName: " << fileName << endl;
        cout << "fileType: " << fileType << endl;
        cout << "fileSize: " << fileSize << endl;
        cout << "pageCount: " << pageCount << endl;
    }
};

class Video : public File {
private: 
	string resolution;
	int duration;
	
public:
    Video(string name, int size, string res, int dur) : File(name, "Video", size), resolution(res), duration(dur) {}

    void open() {
        cout << "fileName: " << fileName << endl;
        cout << "fileType: " << fileType << endl;
        cout << "fileSize: " << fileSize << endl;
        cout << "resolution: " << resolution << endl;
        cout << "duration: " << duration << endl;
    }
};

class Image : public File {
private:
	int width;
	int height;
	
public:
    Image(string name, int size, int w, int h) : File(name, "Image", size), width(w), height(h) {}

    void open() {
        cout << "fileName: " << fileName << endl;
        cout << "fileType: " << fileType << endl;
        cout << "fileSize: " << fileSize << endl;
        cout << "fileSize: " << width << "x" << height << endl;
    }
};

// Ham thong ke so luong cac file moi loai
void sortFile(vector<File*> files){
	int t1 = 0, t2 = 0, t3 = 0;
	for(File* file : files){
		if(file->Type() == "Document") t1++;
		else if(file->Type() == "Video") t2++;
		else if(file->Type() == "Image") t3++;
	}
	
	cout << "Number of Document files: " << t1 << endl;
    cout << "Number of Video files: " << t2 << endl;
    cout << "Number of Image files: " << t3 << endl;
}

int main() {
	// Khoi tao mot so file
    vector<File*> files;
    files.push_back(new Document("LapTrinhC.pdf", 1024, 200));
    files.push_back(new Video("lesson1.mp4", 4000, "FullHD", 90));
    files.push_back(new Image("image1.png", 512, 800, 600));
    files[0]->open();
    
    sortFile(files);
    
    // Giai phong bo nho
    for (File* file : files) {
        delete file;
    }

    return 0;
}

