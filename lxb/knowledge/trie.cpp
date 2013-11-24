#include <memory>   //unique_ptr
#include <iostream>

using namespace std;

class Trie{
public:
	bool insert(cosnt string &s){
		auto* p = root.get();

		for (const char& c:s){
			if (p->leaves.find(c) == p->leaves.end()){
				p->leaves[c] = unique_ptr<TrieNode>(new TrieNode);
			}

			p = p->leaves[c].get();
		}

		//already exist
		if (p->isWord){
			return false;
		}else{
			p->isWord = true;
			return true;
		}
	}

	string GetShortestUniquePrefix(const string &s){
		auto* p = root.get();

		string result;
		for (const char& c:s){
			if (p->leaves.find(c) != p->leaves.end()){
				result += c;
				p = p->leaves[c].get();
			}else{
				return result;
			}
		}

		return result;
	}
	
private:
	struct TrieNode{
		bool isWord = false;
		unordered_map<char, unique_ptr<TrieNode> > leaves;
	};

	unique_ptr<TrieNode> root = unique_ptr<TrieNode>(new TrieNode);
};

int main()
{
	Trie trie;
	trie.insert("abc");
	trie.insert("adf");
	trie.GetShortestUniquePrefix("abd");
}

