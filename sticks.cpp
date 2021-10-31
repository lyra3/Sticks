/*  Sticks
 *  By Lyra Sullenberger, Chomas Atter, Sebastian Howe, and Telford
 *
 *  This is the only comment in the whole code
 *  Get bodied
 */


#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
using namespace std;

struct player{
	int lh;
	int rh;
};

struct gamestate{
	bool ingame;
	struct player p1;
	struct player p2;
};

void turn(struct gamestate *game, int currentPlayer){
	printf("It is player %d's turn.\n", currentPlayer);
	struct player* p;
	struct player* op;
	if(currentPlayer == 1){
	       	p = &game->p1;
		op = &game->p2;
	}
	else{
	       	p = &game->p2;
		op = &game->p1;
	}
	char bignus;
	if((p->lh == 0 && p->rh%2 == 0) || (p->rh == 0 && p->lh%2 == 0)){
		cout << "Attack or split? (a/s)\n";
		cin >> bignus;
		while(bignus != 'a' && bignus != 's'){
			cout << "dees(a/s)\n";
			cin >> bignus;
		}
		if(bignus == 's'){
			if(p->lh == 0){
				p->rh/=2;
				p->lh = p->rh;
			}
			else{
				p->lh/=2;
				p->rh = p->lh;
			}
			cout << "End turn.\n";
			return;
		}
	}
	if(p->lh && p->rh){
		cout << "Which hand will you attack with? (l/r)\n";
		cin >> bignus;
		while(bignus != 'l' && bignus != 'r'){
			cout << "boy if you dont (l/r)\n";
			cin >> bignus;
		}
	}
	else{
		if(p->lh == 0) bignus = 'r';
		else bignus = 'l';
	}
	int attack;
	if(bignus == 'l') attack = p->lh;
	else attack = p->rh;
	if(op->lh && op->rh){
		cout << "Which hand will you attack? (l/r)\n";
		cin >> bignus;
		while(bignus != 'l' && bignus != 'r'){
			cout << "h (l/r)\n";
			cin >> bignus;
		}
	}
	else{
		if(op->lh == 0) bignus = 'r';
		else bignus = 'l';
	}
	if(bignus == 'l') op->lh = (op->lh + attack)%5;
	else op->rh = (op->rh + attack)%5;
	cout << "End turn.\n";
}

bool endgame(int lh1, int rh1, int lh2, int rh2){
	if(lh1 == 0 && rh1 == 0){
		cout << "Player 2 wins!\n";
		return true;
	}
	else if(lh2 == 0 && rh2 == 0){
		cout << "Player 1 wins!\n";
		return true;
	}
	else{
		printf("P1: %d %d P2: %d %d\n", lh1, rh1, lh2, rh2);
		return false;
	}
}

int main(){
start:
	cout << "New game? (y/n)\n";
	char input;
	cin >> input;
	while(input != 'y' && input != 'n' && input != 'l'){
		cout << "bro just answer the question (y/n)\n";
		cin >> input;
	}
	if(input == 'n') return 0;
	else if(input == 'l'){
		cout << "Line 72: if((((players.at(currentPlayer).at(0) == 0) || ((players.at(currentPlayer).at(1) == 0)) && (players.at(currentPlayer).at(1) % 2 == true))) || (((players.at(currentPlayer).at(0) == 0)) && (players.at(currentPlayer).at(1) % 2 == true))(players.at(currentPlayer).at(1) == 0) || ((players.at(currentPlayer).at(0) == 0)))\n";
			goto start;
	}
	struct gamestate game;
	game.ingame = true;
	game.p1.lh = 1;
	game.p1.rh = 1;
	game.p2.lh = 1;
	game.p2.rh = 1;
	while(1){
		bool end = endgame(game.p1.lh, game.p1.rh, game.p2.lh, game.p2.rh);
		if(end) break;
		turn(&game, 1);
		end = endgame(game.p1.lh, game.p1.rh, game.p2.lh, game.p2.rh);
		if(end) break;
		turn(&game, 2);
	}
	goto start;	
}
