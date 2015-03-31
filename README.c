//Same-number-of-friends-algorithm -- Finds two people with the same number of friends

/*There are n ≥ 2 people in a room. Prove that there exist two
among them having equal numbers of friends in that room. (Friendship is
always mutual.)
*/

/*
The ALgorithm generates random friends for specified n number of people and detects if two has same 
number of friends.
*/

#include <stdio.h>
#include <time.h>

int main(void){
	srand(time(NULL));
	int num_equal = 0;
	int t;
	int num_run = 500;
	int num_people = rand()%40+2;
	
	printf("Number of people: %d\n", num_people);
	for(t = 0; t < num_run; t++){
	
	int people[num_people];
	int i;
	for(i = 0; i < num_people; i++){
		people[i] = i;
	}
	
	int friend[num_people];
	for(i = 0; i < num_people; i++){
		friend[i] = 0;
	}
	
	
	int fri_ind[num_people][num_people];
	int j;
	int check[num_people];
	for(i = 0; i < num_people; i++){
		check[i] = -1;
	}
	int k;
	int random;
	int count = 0;
	for(i = 0; i < num_people; i++){
		for(j = 0; j < people[i]; j++){
			random = rand()%num_people;
			while(1 > 0){
				for(k = 0; k < people[i]; k++){
					if(check[k] == random){
						count++;
						break;
					}
				}
				if(count == 0){
					break;
				}
				else{
					random = rand()%num_people;
				}
				count = 0;
			}
			check[j] = random;
			fri_ind[i][j] = random;
		}
		for(k = 0; k < num_people; k++){
			check[k] = -1;
		}
	}
	
	
	for(i = 0; i < num_people; i++){
		for(j = 0; j < people[i]; j++){
			friend[fri_ind[i][j]]++;
		}
	}
	
	printf("No. of friends each has: ");
	for(i = 0; i < num_people; i++){
		printf("%d ", friend[i]);
	}
	int count1 = 0;
	for(i = 0; i < num_people; i++){
		for(j = 0; j < num_people; j++){
			if(friend[i] == friend[j]){
				count1++;
			}
		}
		if(count1 != 0){
			num_equal++;
			break;
		}
	}
	printf("\n");
	printf("\n");
	}
	printf("Number of run-time: %d\n", num_run);
	printf("Number of pair with same number of friends found each run-time: %d\n", num_equal);
	return 0;
}
