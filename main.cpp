#include <cstdio>
#include <cstdlib>

#include "sort.h"
#include "bs_tree.h"
#include "timer.h"
#include "random_generator.h"

int main(int argc, char* argv[]) {

	random_generator rg;

	timer t;
	int n, direction;




/*
 * check arguments
 */
	if (argc > 1)
	{
		n = atoi(argv[1]);
		n = (n < 1) ? 1 : n;
	}
	else
	{
		cout << argv[0] << " [n] [direction] [tree]" << endl;
		cout << "[n]              size of the random string array" << endl;
		cout << "[direction]            -1: input is sorted descending" << endl;
		cout << "                 1: input is sorted ascending" << endl;
		cout << "                 0: input is random" << endl;
		cout << endl;
		return 0;
	}

	if (argc > 2)
		direction = atoi(argv[2]);
	else
		direction = 0;




/*
 * allocated and generate integer array
 */

	bs_tree bs;
	int* input_array;



	t.start();
	if (direction == 0)
		input_array = create_random(n);
	else
	{
		if (direction < 0)
			input_array = create_reverse_sorted(n);
		else
			input_array = create_sorted(n);
	}
	t.stop();

	cout << "Timer (generate): " << t << endl;

	for (int i = 0; (i < n) && (i < 20); i++)
		cout << input_array[i] << endl;
	cout << endl;

/*
 * run algorithms
 */
 cout << "Running sort using BS trees: " << endl;
 t.start();
 for (int i = 0; i < n; i++)
	 bs.insert(input_array[i]);
 n = bs.convert(input_array, n);
 t.stop();

	cout << "Timer (sort): " << t << endl;



/*
 * check output
 */


	cout << "New size: " << n << endl;
	cout << "Duplicates: " << bs.bs_tree_i_info.duplicates << endl;





	if (check_sorted(input_array, 0, n-1))
		cout << "The output is sorted!" << endl;
	else
		cout << "ERROR: The output is not sorted!" << endl;
	// for (int i = 0; (i < n) && (i < 20); i++)
	// 	cout << input_array[i] << endl;
//	cout << endl;

/*
 * free allocated storage
 */
delete[] input_array;
//reset the struct

bs.reset();

	return 0;
}
