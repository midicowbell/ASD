#pragma once
class DSU {
	int* _parent;
	size_t _size;
	int* _rank;
public:
	DSU(size_t size);
	void unite(int x1, int x2);
	int find(int x);
	~DSU();
	size_t size() { return _size; }
};
