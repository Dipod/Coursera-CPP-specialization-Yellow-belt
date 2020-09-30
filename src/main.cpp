/*
 Предисловие

 Если вы не уверены, стоит ли вам сначала пройти наш первый курс, или у вас достаточно знаний,
 чтобы начать с «Жёлтого пояса», попробуйте решить эту задачу.
 Если вы не понимаете её условие или не можете быстро решить, скорее всего, вам надо сначала пройти «Белый пояс»

 Условие

 В этой задаче вам надо разработать класс Matrix для представления целочисленной матрицы.
 Более подробно, класс Matrix должен иметь:

 конструктор по умолчанию, который создаёт матрицу с нулём строк и нулём столбцов
 конструктор от двух целочисленных параметров: num_rows и num_cols, — которые задают количество строк и столбцов
 матрицы соответственно
 метод Reset, принимающий два целочисленных параметра, которые задают новое количество строк и столбцов матрицы соответственно;
 метод Reset меняет размеры матрицы на заданные и обнуляет все её элементы
 константный метод At, который принимает номер строки и номер столбца
 (именно в этом порядке; нумерация строк и столбцов начинается с нуля) и возвращает значение в соответствущей ячейке матрицы
 неконстантный метод At с такими же параметрами,
 но возвращающий ссылку на значение в соответствущей ячейке матрицы
 константные методы GetNumRows и GetNumColumns, которые возвращают количество строк и столбцов матрицы соответственно

 Если количество строк или количество столбцов, переданное в конструктор класса Matrix или метод Reset,
 оказалось отрицательным, то должно быть выброшено стандартное исключение out_of_range.

 Это же исключение должен бросать метод At, если переданная в него ячейка выходит за границы матрицы.

 Кроме того, для класса Matrix должны быть определены следующие операторы:

 оператор ввода из потока istream; формат ввода простой — сначала задаётся количество строк и столбцов
 (именно в этом порядке), а затем все элементы матрицы: сначала элемент первой строки и первого столбца,
 затем элемент первой строки и второго столбца и так далее

 оператор вывода в поток ostream; он должен выводить матрицу в том же формате,
 в каком её читает оператор ввода, — в первой строке количество строк и столбцов,
 во второй — элементы первой строки, в третьей — элементы второй строки и т.д.

 оператор проверки на равенство (==): он должен возвращать true,
 если сравниваемые матрицы имеют одинаковый размер и все их соответствующие элементы равны между собой,
 в противном случае он должен возвращать false.

 оператор сложения: он должен принимать две матрицы и возвращать новую матрицу, которая является их суммой;
 если переданные матрицы имеют разные размеры этот оператор должен выбрасывать стандартное исключение invalid_argument.

 Вам дана заготовка решения, а также пример ввода и вывода. Когда вы реализуете класс Matrix, вы можете использовать этот пример,
 чтобы убедиться, что ваш код работает правильно.

 Важно! Пример не проверяет выполнение всех требований, приведённых в условии.

 Примечание

 Матрицы с нулём строк или нулём столбцов считаются пустыми. Любые две пустые матрицы равны.
 Сумма двух пустых матриц также является пустой матрицей.

 Автор задачи — Дмитрий Минченко

 #include <iostream>
 #include <fstream>
 #include <stdexcept>
 #include <vector>

 using namespace std;

 // Реализуйте здесь
 // * класс Matrix
 // * оператор ввода для класса Matrix из потока istream
 // * оператор вывода класса Matrix в поток ostream
 // * оператор проверки на равенство двух объектов класса Matrix
 // * оператор сложения двух объектов класса Matrix

 int main() {
 Matrix one;
 Matrix two;

 cin >> one >> two;
 cout << one + two << endl;
 return 0;
 }

 Пример ввода

 3 5
 6 4 -1 9  8
 12 1  2 9 -5
 -4 0 12 8  6

 3 5
 5 1  0 -8 23
 14 5 -6  6  9
 8 0  5  4  1

 Пример вывода

 3 5
 11 5 -1 1 31
 26 6 -4 15 4
 4 0 17 12 7

 */

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

// Реализуйте здесь
// * класс Matrix
// * оператор ввода для класса Matrix из потока istream
// * оператор вывода класса Matrix в поток ostream
// * оператор проверки на равенство двух объектов класса Matrix
// * оператор сложения двух объектов класса Matrix

class Matrix {
public:
	Matrix() {

	}

	Matrix(const int &num_rows, const int &num_cols) {
		Reset(num_rows, num_cols);
	}

	void Reset(const int &num_rows, const int &num_cols) {

		if (num_rows < 0) {
			throw out_of_range("Number of rows less than zero");
		}

		if (num_cols < 0) {
			throw out_of_range("Number of columns less than zero");
		}

		matrix.clear();

		if (num_rows != 0 && num_cols != 0) {
			matrix.resize(num_rows);
			for (auto &col : matrix) {
				col.resize(num_cols, 0);
			}
		}
	}

	int At(const int &num_rows, const int &num_cols) const {
		CheckOutOfRange(num_rows, num_cols);
		return matrix[num_rows][num_cols];
	}

	int& At(const int &num_rows, const int &num_cols) {
		CheckOutOfRange(num_rows, num_cols);
		return matrix[num_rows][num_cols];
	}

	int GetNumRows() const {
		return matrix.size();
	}

	int GetNumColumns() const {
		if (matrix.size() == 0) {
			return 0;
		} else {
			return matrix[0].size();
		}
	}

	bool operator==(const Matrix &rhs) const {
		return this->matrix == rhs.matrix;
	}

private:
	vector<vector<int>> matrix;
	void CheckOutOfRange(const int &num_rows, const int &num_cols) const {
		if (num_rows < 0) {
			throw out_of_range("Row number less than zero");
		}
		if (num_cols < 0) {
			throw out_of_range("Column number less than zero");
		}
		if (num_rows >= this->GetNumRows()) {
			throw out_of_range("Row number greater than number of matrix rows");
		}
		if (num_cols >= this->GetNumColumns()) {
			throw out_of_range(
					"Column number greater than number of matrix columns");
		}
	}
};

istream& operator>>(istream &stream, Matrix &matrix) {
	int rows, columns;
	stream >> rows >> columns;
	matrix.Reset(rows, columns);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			stream >> matrix.At(i, j);
		}
	}
	return stream;
}

ostream& operator<<(ostream &stream, const Matrix &matrix) {
	int columns = matrix.GetNumColumns(), rows = matrix.GetNumRows();
	stream << rows << ' ' << columns << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			stream << matrix.At(i, j) << ' ';
		}
		stream << endl;
	}
	return stream;
}

Matrix operator+(const Matrix &lhs, const Matrix &rhs) {
	int columns = lhs.GetNumColumns();
	int rows = lhs.GetNumRows();
	if (columns != rhs.GetNumColumns() || rows != rhs.GetNumRows()) {
		throw invalid_argument("Matrices have different sizes");
	}
	Matrix result(rows, columns);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			result.At(i, j) = lhs.At(i, j) + rhs.At(i, j);
		}
	}
	return result;
}

int main() {
	Matrix one;
	Matrix two;

	cin >> one >> two;
	cout << one + two << endl;
	return 0;
}
