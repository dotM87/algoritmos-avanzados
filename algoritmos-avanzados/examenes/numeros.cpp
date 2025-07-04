#include <bits/stdc++.h>
using namespace std;

struct Punto {
	int x, y;

	bool operator <(const Punto& otro) const {
		return (x < otro.x) || (x == otro.x && y < otro.y);
	}
};

int mcd (int a, int b){
	return b == 0 ? a : mcd(b, a % b);
}

struct Direccion {
	int dx, dy;

	Direccion (int _dx, int _dy){
		int g = mcd(abs(_dx), abs(_dy));
		dx = (g != 0) ? _dx / g : 0;
		dy = (g != 0) ? _dy / g : 0;
	}

	bool operator==(const Direccion& otro) const {
		return dx == otro.dx && dy==otro.dy;
	}

	bool operator <(const Direccion& otro) const {
		return (dx < otro.dx) || (dx == otro.dx && dy < otro.dy);
	}
};

int ProdCruz(const Direccion& a, const Direccion& b){
	return a.dx * b.dy - a.dy * b.dx;
}

struct Nodo {
	Punto p;
	set <Direccion> direcciones;
};

int main() {
	int n; cin >> n;

	map <Punto, Nodo> grafo;

	for (int i = 0; i < n; i++){
		Punto a, b;
		cin >> a.x >> a.y>> b.x >> b.y;

		Direccion dirAB(b.x - a.x, b.y - a.y);
		Direccion dirBA(a.x - b.x, a.y - b.y);

		grafo[a].p = a;
		grafo[b].p = b;

		grafo[a].direcciones.insert(dirAB);
		grafo[b].direcciones.insert(dirBA);
	}

	int total_ang = 0;
	for (const auto& [_, nodo] : grafo){
		vector<Direccion> dirs (nodo.direcciones.begin(), nodo.direcciones.end());
		int k = dirs.size();
		for (int i = 0; i < k; i++){
			for (int j = i+1; j < k; j++){
				if (ProdCruz(dirs[i], dirs[j]) != 0){
					total_ang++;
				}
			}
		}
	}

	cout << total_ang << endl;
	return 0;
}