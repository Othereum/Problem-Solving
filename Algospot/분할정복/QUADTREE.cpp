// https://algospot.com/judge/problem/read/QUADTREE

#include <iostream>
#include <memory>
#include <array>
#include <utility>
using namespace std;

struct FQuadTree
{
	char pixel;
	array<unique_ptr<FQuadTree>, 4> next;
};

template <typename F>
void Iterate(const FQuadTree& Tree, F&& func)
{
	func(Tree.pixel);
	if (Tree.pixel == 'x')
		for (const auto& next : Tree.next)
			Iterate(*next, func);
}

template <typename T>
T Next() { T t; cin >> t; return t; }

void MakeQuadTree(FQuadTree& Tree)
{
	cin >> Tree.pixel;
	if (Tree.pixel == 'x')
	{
		for (auto& next : Tree.next)
		{
			next.reset(new FQuadTree);
			MakeQuadTree(*next);
		}
	}
}

void ReverseTopBottom(FQuadTree& Tree)
{
	// 기저 사레: 해당 노드가 단말 노드임
	if (Tree.pixel != 'x') return;

	swap(Tree.next[0], Tree.next[2]);
	swap(Tree.next[1], Tree.next[3]);

	for (const auto& next : Tree.next)
		ReverseTopBottom(*next);
}

int main()
{
	for (auto i = Next<int>(); i > 0; --i)
	{
		FQuadTree Image;
		MakeQuadTree(Image);
		ReverseTopBottom(Image);
		Iterate(Image, [](char pixel) {cout << pixel; });
		cout << '\n';
	}
}