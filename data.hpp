#ifndef __DATA_HPP__
#define __DATA_HPP__

#include <iostream>
#include <vector>
#include <unordered_set>
#include "feature.hpp"

using namespace std;

class Pair {
public:
	size_t u;
	size_t i;
	size_t j;
	inline Pair(size_t _u, size_t _i, size_t _j) {
        u = _u; i = _i; j = _j;
    }
	Pair() {}
	friend ostream& operator<<(ostream& c, Pair & p) {
        c << "(" << p.u << ", " << p.i << ", " << p.j << ")";
        return c;
	}
};

/* 用來存 (i, yui) 的tuple */
class Pair_i_yui {
public:
	size_t i;
	double y;
	Pair_i_yui(size_t _i, double _y) {
		i = _i; y = _y;
	}
	Pair_i_yui() {}
};

/* 提供給 train 和 test 實作的 interface */
class __Data {
protected:
	size_t _Nuser; 
	size_t _Nitem;
public:
	__Data() {
		_Nuser = 0;
		_Nitem = 0;
		i_set = NULL;
		document = NULL;
	}
	~__Data() {
        delete [] i_set;
		delete [] document;
	}
	virtual void Read_File(const char * filename) = 0;
    // 所有有用到的 u，對於 train，就是從 0 ~ Nuser, 對於 test 是一個子集合
	unordered_set<size_t> u_set;
    // 其實就是 Iu+ 這個集合
    unordered_set<size_t> * i_set;
    // 所有必需要測試與計算的 document 集合，對於 test 來說，有些 document 是空的
	vector<Pair_i_yui> * document;
	inline size_t Nuser() const {return _Nuser;}
	inline size_t Nitem() const {return _Nitem;}
	/* 對每個 i_set[u] 的 i，給出 neg_ratio 個 j */
	vector<Pair> draw_sample(int ji_ratio) const;
	vector<Pair> draw_sample(size_t u, int ji_ratio) const;
};

class Train_Data : public __Data {
public:
	void Read_File(const char * filename);
};

class Test_Data : public __Data {
public:
	void Read_File(const char * filename);
	inline void set_Nuser(size_t __Nuser) {_Nuser = __Nuser;}
};

class DataSet {
public:
	Train_Data train;
	Test_Data test;
	Feature * user;
	Feature * item;
	DataSet();
	~DataSet();
	inline size_t Nuser() const {return _Nuser;}
	inline size_t Nitem() const {return _Nitem;}
	void Read_File(const char * train_filename, const char * test_filename);
private:
	size_t _Nuser;
	size_t _Nitem;
};

#endif
