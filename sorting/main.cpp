#include<iostream>
#include<array>
#include<algorithm>
#include<chrono>
#include<vector>
#include<memory>

using namespace std;

template<class container>
void bublesort(container& c){
	for(unsigned int i = 0; i < c.size() - 1; i++){
		for(unsigned int j = 0; j < c.size() - 1 - i; j++){
			if(c[j] > c[j + 1]){
//				c[j] ^= c[j + 1];
//				c[j + 1] ^= c[j];
//				c[j] ^= c[j + 1];
				swap(c[j], c[j + 1]);
			}
		}
	}
}

template<class container>
void selectionsort(container& c){
	int indexmin;
	for(unsigned int i = 0; i < c.size(); i++){
		indexmin = i;
		for(unsigned int j = i + 1; j < c.size(); j++){
			if(c[j] < c[indexmin]){
//				min = c[j];
				indexmin = j;
			}
		}
		if(c[i] != c[indexmin]){
//			c[i] ^= c[indexmin];
//			c[indexmin] ^= c[i];
//			c[i] ^= c[indexmin];
			swap(c[i], c[indexmin]);
		}
	}
}

template<class container>
void printElements(const container& c){
	for(unsigned int i = 0; i < c.size(); i++){
		cout << c[i] << " ";
	}
	cout << endl;
}

vector<int> merge(vector<int> c1, vector<int> c2){
	auto it1 = c1.begin();
	auto it2 = c2.begin();
	vector<int> res(c1.size() + c2.size());
	int index = 0;
	while(it1 != c1.end() || it2 != c2.end()){
		if((it1 != c1.end() && *it1 < *it2) || it2 == c2.end()){
//			res.push_back (*it1);
			res[index] = *it1;
			it1++;
			index++;
		}
		else {
//			res.push_back (*it2);
			res[index] = *it2;
			it2++;
			index++;
		}
	}
	return res;
}

vector<int> mergeSort(vector<int> v){
	if(v.size () < 2) return v;
//	unique_ptr<int> half = make_unique<int>(v.size() / 2);
	int half = v.size () / 2;
	vector<int> left(v.begin (), v.begin () + half);
	vector<int> right(v.begin () + half, v.end());
	return merge(mergeSort (left), mergeSort (right));
}

vector<int> quickSort(vector<int> v){
	if(v.size() < 2) return v;
	auto left = v.begin ();
	auto right = v.end() - 1;
	while(right > left){
		if(*left > *right){
			if(right - 1 != left) iter_swap(right, right - 1);
			iter_swap(right, left);
			right--;
//			left++;
		}else{
			left++;
		}
//		cout << "derecha: " << *right << endl;
	}
//	cout << "izquierda: " << *left << ", derecha: " << *right << endl;
	vector<int> result;
	for(int i: quickSort (vector<int>(v.begin (), left))) result.push_back (i);
	result.push_back (*left);
	for(int j : quickSort (vector<int>(left + 1, v.end()))) result.push_back (j);
	return result;
}

template<class container>
void insertionSort(container& c){
	int* num = new int;
	int* j = new int;
	for(unsigned int i = 1; i < c.size(); i++){
		*num = c[i];
		*j = i - 1;
		while(*j >= 0 && c[*j] > *num){
			c[*j + 1] = c[*j];
			*j -= 1;
		}
		c[*j + 1] = *num;
	}
	delete num;
	delete j;
}

template<class container>
void dance(container& c, int left, int right){
	if(left >= right) return;
	int originalLeft = left;
	int originalRight = right;
	bool leftChanges = true;
	while(right > left){
		if(c[left] > c[right]){
			swap(c[left], c[right]);
			leftChanges = !leftChanges;
		}
		if(leftChanges){
			left++;
		}else{
			right--;
		}
	}
	dance(c, originalLeft, left - 1);
	dance(c, right + 1, originalRight);
}

void iterdance(vector<int>& v, vector<int>::iterator left, vector<int>::iterator right){
	if(left >= right) return;
	auto originalLeft = left;
	auto originalRight = right;
	bool leftChanges = true;
	while(right > left){
		if(*left > *right){
			iter_swap(left, right);
			leftChanges = !leftChanges;
		}
		if(leftChanges){
			left++;
		}else{
			right--;
		}
	}
	iterdance(v, originalLeft, left - 1);
	iterdance(v, right + 1, originalRight);
}

int main(){
	array<int, 11> ar = {99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0};
	array<int, 100> ar1 = {22, 19, 115, 81, 71, 166, 39, 105, 174, 145, 29, 77, 11, 168, 151, 164, 108, 120, 193, 163, 32, 172, 89, 89, 113, 141, 171, 163, 151, 93, 106, 30, 154, 120, 111, 193, 106, 179, 40, 164, 76, 96, 146, 138, 89, 123, 181, 11, 126, 88, 122, 187, 58, 173, 53, 185, 59, 67, 151, 1, 116, 85, 75, 53, 57, 70, 142, 186, 112, 172, 43, 42, 124, 182, 106, 117, 40, 188, 9, 151, 22, 152, 32, 137, 95, 13, 115, 26, 89, 20, 96, 49, 148, 133, 74, 173, 106, 9, 50, 163};
	array<int, 100> ar2 = {22, 19, 115, 81, 71, 166, 39, 105, 174, 145, 29, 77, 11, 168, 151, 164, 108, 120, 193, 163, 32, 172, 89, 89, 113, 141, 171, 163, 151, 93, 106, 30, 154, 120, 111, 193, 106, 179, 40, 164, 76, 96, 146, 138, 89, 123, 181, 11, 126, 88, 122, 187, 58, 173, 53, 185, 59, 67, 151, 1, 116, 85, 75, 53, 57, 70, 142, 186, 112, 172, 43, 42, 124, 182, 106, 117, 40, 188, 9, 151, 22, 152, 32, 137, 95, 13, 115, 26, 89, 20, 96, 49, 148, 133, 74, 173, 106, 9, 50, 163};
	array<int, 100> ar3 = {22, 19, 115, 81, 71, 166, 39, 105, 174, 145, 29, 77, 11, 168, 151, 164, 108, 120, 193, 163, 32, 172, 89, 89, 113, 141, 171, 163, 151, 93, 106, 30, 154, 120, 111, 193, 106, 179, 40, 164, 76, 96, 146, 138, 89, 123, 181, 11, 126, 88, 122, 187, 58, 173, 53, 185, 59, 67, 151, 1, 116, 85, 75, 53, 57, 70, 142, 186, 112, 172, 43, 42, 124, 182, 106, 117, 40, 188, 9, 151, 22, 152, 32, 137, 95, 13, 115, 26, 89, 20, 96, 49, 148, 133, 74, 173, 106, 9, 50, 163};
	auto t1 = chrono::high_resolution_clock::now();
	bublesort(ar1);
	auto t2 = chrono::high_resolution_clock::now();
	sort(ar2.begin(), ar2.end());
	auto t3 = chrono::high_resolution_clock::now();
//	printElements(ar);
	auto casero = chrono::duration_cast<chrono::microseconds>(t2 - t1);
	auto algo = chrono::duration_cast<chrono::microseconds>(t3 - t2);
	cout << "El de la burbuja tarda " << casero.count () << " microsegundos" << endl;
	cout << "El de Alexander Stepanov tarda " << algo.count () << " microsegundos" << endl;
	cout << "\nSELECTION SORT\n\n";
	t1 = chrono::high_resolution_clock::now();
	selectionsort(ar3);
	t2 = chrono::high_resolution_clock::now();
	auto dif = chrono::duration_cast<chrono::microseconds>(t2 - t1);
	cout << "El de seleccion tarda " << dif.count() << " microsegundos" << endl;
	cout << "\n\nMerge sort\n\n";
	vector<int> v1 = {1, 3, 6, 8};
	vector<int> v2 = {2, 4};
	vector<int> vr = {99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0};
	vector<int> vl = {22, 19, 115, 81, 71, 166, 39, 105, 174, 145, 29, 77, 11, 168, 151, 164, 108, 120, 193, 163, 32, 172, 89, 89, 113, 141, 171, 163, 151, 93, 106, 30, 154, 120, 111, 193, 106, 179, 40, 164, 76, 96, 146, 138, 89, 123, 181, 11, 126, 88, 122, 187, 58, 173, 53, 185, 59, 67, 151, 1, 116, 85, 75, 53, 57, 70, 142, 186, 112, 172, 43, 42, 124, 182, 106, 117, 40, 188, 9, 151, 22, 152, 32, 137, 95, 13, 115, 26, 89, 20, 96, 49, 148, 133, 74, 173, 106, 9, 50, 163};
	t1 = chrono::high_resolution_clock::now();
//	printElements(mergeSort(vl));
	mergeSort (vl);
	t2 = chrono::high_resolution_clock::now();
	dif = chrono::duration_cast<chrono::microseconds>(t2 - t1);
	cout << "\nEl de unir tarda " << dif.count() << " microsegundos" << endl;
	cout << "\n\nQuick sort\n\n";
	vector<int> v = {3, 7, 8, 5, 2, 1, 9, 5, 4};
	t1 = chrono::high_resolution_clock::now();
	quickSort (vl);
	t2 = chrono::high_resolution_clock::now();
	dif = chrono::duration_cast<chrono::microseconds>(t2 - t1);
//	printElements(quickSort (vl));
	cout << "\nEl quick tarda " << dif.count() << " microsegundos" << endl;
	cout << "\n\nInsertion sort\n\n";
	ar1 = {22, 19, 115, 81, 71, 166, 39, 105, 174, 145, 29, 77, 11, 168, 151, 164, 108, 120, 193, 163, 32, 172, 89, 89, 113, 141, 171, 163, 151, 93, 106, 30, 154, 120, 111, 193, 106, 179, 40, 164, 76, 96, 146, 138, 89, 123, 181, 11, 126, 88, 122, 187, 58, 173, 53, 185, 59, 67, 151, 1, 116, 85, 75, 53, 57, 70, 142, 186, 112, 172, 43, 42, 124, 182, 106, 117, 40, 188, 9, 151, 22, 152, 32, 137, 95, 13, 115, 26, 89, 20, 96, 49, 148, 133, 74, 173, 106, 9, 50, 163};
	t1 = chrono::high_resolution_clock::now();
	insertionSort(ar1);
	t2 = chrono::high_resolution_clock::now();
	dif = chrono::duration_cast<chrono::microseconds>(t2 - t1);
	cout << "\nLa insercion tarda " << dif.count() << " microsegundos" << endl;
//	printElements(ar1);
	cout << "\nEl baile\n" << endl;
//	cout << "Nuestro vector: ";
	v = {3, 7, 8, 5, 2, 1, 9, 5, 4};
	vl = {22, 19, 115, 81, 71, 166, 39, 105, 174, 145, 29, 77, 11, 168, 151, 164, 108, 120, 193, 163, 32, 172, 89, 89, 113, 141, 171, 163, 151, 93, 106, 30, 154, 120, 111, 193, 106, 179, 40, 164, 76, 96, 146, 138, 89, 123, 181, 11, 126, 88, 122, 187, 58, 173, 53, 185, 59, 67, 151, 1, 116, 85, 75, 53, 57, 70, 142, 186, 112, 172, 43, 42, 124, 182, 106, 117, 40, 188, 9, 151, 22, 152, 32, 137, 95, 13, 115, 26, 89, 20, 96, 49, 148, 133, 74, 173, 106, 9, 50, 163};
//	printElements(v);
	t1 = chrono::high_resolution_clock::now();
	dance(vl, 0, vl.size () - 1);
	t2 = chrono::high_resolution_clock::now();
	dif = chrono::duration_cast<chrono::microseconds>(t2 - t1);
	cout << "El baile tarda " << dif.count () << " microsegundos" << endl;
//	cout << "Despues de los cambios: ";
//	printElements(vl);
	cout << "\nIterdance\n" << endl;
	vl = {22, 19, 115, 81, 71, 166, 39, 105, 174, 145, 29, 77, 11, 168, 151, 164, 108, 120, 193, 163, 32, 172, 89, 89, 113, 141, 171, 163, 151, 93, 106, 30, 154, 120, 111, 193, 106, 179, 40, 164, 76, 96, 146, 138, 89, 123, 181, 11, 126, 88, 122, 187, 58, 173, 53, 185, 59, 67, 151, 1, 116, 85, 75, 53, 57, 70, 142, 186, 112, 172, 43, 42, 124, 182, 106, 117, 40, 188, 9, 151, 22, 152, 32, 137, 95, 13, 115, 26, 89, 20, 96, 49, 148, 133, 74, 173, 106, 9, 50, 163};
	t1 = chrono::high_resolution_clock::now();
	iterdance(vl, vl.begin (), vl.end() - 1);
	t2 = chrono::high_resolution_clock::now();
	dif = chrono::duration_cast<chrono::microseconds>(t2 - t1);
	cout << "El baile iterador tarda " << dif.count () << " microsegundos" << endl;
	return 0;
}
