#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include "data.hpp"

using namespace std;

void Train_Data::Read_File(const char * filename) {
	fstream file;
	file.open(filename, ios::in);
	assert(file != NULL);
	
	file >> _Nuser >> _Nitem;
	i_set = new unordered_set<size_t>[_Nuser];
	#ifdef TRAIN_DOC
	document = new vector<Pair_i_yui>[_Nuser];
	#endif
	{
		int y;
		size_t u;
		size_t i;
		while (file >> y >> u >> i) {
			u_set.insert(u);
			i_set[u].insert(i);
		}
	}
	#ifdef TRAIN_DOC
	for (size_t u = 0; u < _Nuser; u++)
		for (size_t i = 0; i < _Nitem; i++)
			document[u].push_back(Pair_i_yui(i, 0.));
	#endif
	file.close();
}

vector<Pair> __Data::draw_sample(int ji_ratio) const {
	vector<Pair> samples;
    /* 對每個 u 當中的每個 i_set(u) 元素都 sample ji_ratio 個 j*/
	for (size_t u = 0; u < Nuser(); u++) {
		for (unordered_set<size_t>::iterator it = i_set[u].begin(); it != i_set[u].end(); it++) {
			for (size_t Npair = 0; Npair < (size_t)ji_ratio; ) {
				size_t j = rand() % _Nitem;
				if (i_set[u].find(j) == i_set[u].end()) {
					Npair ++;
					samples.push_back(Pair(u, *it, j));
				}
			}
		}
	}
	random_shuffle(samples.begin(), samples.end());
	return samples;
}

vector<Pair> __Data::draw_sample(size_t u, int ji_ratio) const {
	vector<Pair> samples;
    /* 對每個 i_set(u) 元素都 sample ji_ratio 個 j*/
	for (unordered_set<size_t>::iterator it = i_set[u].begin(); it != i_set[u].end(); it++) {
		for (size_t Npair = 0; Npair < (size_t)ji_ratio; ) {
			size_t j = rand() % _Nitem;
			if (i_set[u].find(j) == i_set[u].end()) {
				Npair ++;
				samples.push_back(Pair(u, *it, j));
			}
		}
	}
	random_shuffle(samples.begin(), samples.end());
	return samples;
}

void Test_Data::Read_File(const char * filename) {
	fstream file;
	file.open(filename, ios::in); assert(file != NULL);
	file >> _Nitem;
	i_set = new unordered_set<size_t>[_Nuser];
	document = new vector<Pair_i_yui>[_Nuser];
	
	{
		size_t u;
		while (file >> u) {
            u_set.insert(u);

			bool check[_Nitem][2];
			for (size_t i = 0; i < _Nitem; i++) {
				check[i][0] = false;
				check[i][1] = false;
			}
			
			size_t Ni, i;
			file >> Ni;
			for (size_t ni = 0; ni < Ni; ni++) {
				file >> i;
				check[i][0] = true;
			}
			file >> Ni;
			for (size_t ni = 0; ni < Ni; ni++) {
				file >> i;
				check[i][1] = true;
			}
			
			for (size_t i = 0; i < _Nitem; i++) {
				if (check[i][0]) {
					i_set[u].insert(i);
				}
				if (check[i][0] == true || check[i][1] == false) {
					document[u].push_back(Pair_i_yui(i, 0.));
				}
			}
		}
	}
	file.close();
}

DataSet::DataSet() {
	_Nuser = 0; 
	_Nitem = 0;
	user = NULL;
	item = NULL;
}
DataSet::~DataSet() {
	delete [] user;
	delete [] item;
}
void DataSet::Read_File(const char * train_filename, const char * test_filename) {
	train.Read_File(train_filename);
	_Nuser = train.Nuser();
	_Nitem = train.Nitem();
    /* test file doesn't have Nuser information */
	test.set_Nuser(_Nuser);
	test.Read_File(test_filename);
	user = new Feature(_Nuser);
	item = new Feature(_Nitem);
}
