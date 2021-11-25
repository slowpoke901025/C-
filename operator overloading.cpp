#include <iostream>
#include <math.h>
using namespace std;

class Vector
{
	double *arr;
	int size;

  public:
	//Constructor
	Vector()
	{
		arr = new double[2]();
		size = 2;
	}
	Vector(int size)
	{
		arr = new double[size]();
		this->size = size;
	}
	Vector(int size, double arr[])
	{
		this->size = size;
		this->arr = new double[size]();
		for (int i = 0; i < size; i++)
		{
			this->arr[i] = arr[i];
		}
	}

	//copy constructor
	Vector(const Vector &v)
	{
		this->size = v.size;
		this->arr = new double[size];
		for (int i = 0; i < size; i++)
		{
			this->arr[i] = v.arr[i];
		}
	}

	//destructor
	~Vector()
	{
		delete[] arr;
	}

	//class function
	int getDimension()
	{
		return size;
	}
	void setDimension(int size)
	{
		double *Arr = arr;
		arr = new double[size]();
		for (int i = 0; i < size && i < this->size; i++)
		{
			arr[i] = Arr[i];
		}
		this->size = size;
		delete[] Arr;
	}
	double length()
	{
		double sum = 0;
		for (int i = 0; i < size; i++)
		{
			sum += arr[i] * arr[i];
		}
		return pow(sum, 0.5);
	}

	//operator prototype
	Vector operator=(const Vector &v);
	double &operator[](int index);
	Vector operator+(const Vector &v);
	Vector operator-(const Vector &v);
	void operator+=(const Vector &v);
	void operator-=(const Vector &v);
	void operator*=(double d);
	bool operator==(const Vector &v);
	bool operator!=(const Vector &v);

	friend Vector operator-(Vector v);
	friend Vector operator*(Vector v, double d);
	friend ostream &operator<<(ostream &output, const Vector &v);
};

// operator implementation
Vector Vector::operator=(const Vector &v)
{
	delete[] this->arr;
	this->size = v.size;
	this->arr = new double[size];
	for (int i = 0; i < size; i++)
	{
		this->arr[i] = v.arr[i];
	}

	return *this;
}

double &Vector::operator[](int index)
{
	if (index < size && index >= 0)
		return arr[index];
	double error = 0;
	return error;
}

Vector Vector::operator+(const Vector &v)
{
	if (size != v.size)
	{
		cout << "Dimensions of the two Vectors are different";
		return 0;
	}
	Vector p = *this;
	for (int i = 0; i < size; i++)
	{
		p.arr[i] += v.arr[i];
	}
	return p;
}

Vector Vector::operator-(const Vector &v)
{
	if (size != v.size)
	{
		cout << "Dimensions of the two Vectors are different";
		return 0;
	}
	Vector p = *this;
	for (int i = 0; i < size; i++)
	{
		p.arr[i] -= v.arr[i];
	}
	return p;
}

void Vector::operator+=(const Vector &v)
{
	if (size != v.size)
	{
		cout << "Dimensions of the two Vectors are different";
		return;
	}
	for (int i = 0; i < size; i++)
	{
		arr[i] += v.arr[i];
	}
}

void Vector::operator-=(const Vector &v)
{
	if (size != v.size)
	{
		cout << "Dimensions of the two Vectors are different";
		return;
	}
	for (int i = 0; i < size; i++)
	{
		arr[i] -= v.arr[i];
	}
}

void Vector::operator*=(double d)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] *= d;
	}
}

bool Vector::operator==(const Vector &v)
{
	if (this->size != v.size)
		return 0;
	for (int i = 0; i < size; i++)
	{
		if (this->arr[i] != v.arr[i])
			return 0;
	}
	return 1;
}

bool Vector::operator!=(const Vector &v)
{
	if (this->size != v.size)
		return 1;
	for (int i = 0; i < size; i++)
	{
		if (this->arr[i] != v.arr[i])
			return 1;
	}
	return 0;
}

ostream &operator<<(ostream &output, const Vector &v)
{
	output << "(";
	for (int i = 0; i < v.size - 1; i++)
	{
		output << v.arr[i] << ", ";
	}
	output << v.arr[v.size - 1] << ")\n";
	return output;
}

Vector operator-(Vector v)
{
	Vector p = v;
	for (int i = 0; i < v.size; i++)
	{
		p.arr[i] *= -1;
	}
	return p;
}

Vector operator*(Vector v, double d)
{
	Vector p = v;
	p *= d;

	return p;
}

Vector operator*(double d, Vector v)
{
	Vector p = v;
	p *= d;

	return p;
}

int main(int argc, char *argv[])
{
	cout << "\n------------------Initialization----------------------" << endl;

	double *a = new double[3]{1, 1, 1};
	double *b = new double[5]{1, 1, 1, 1, 1};

	Vector V1(3);
	Vector V2(5, b);
	cout << " V1: " << V1;
	cout << " V2: " << V2;

	cout << "------------------getDimension()------------------" << endl;

	cout << " V1's Dimension: " << V1.getDimension() << endl;
	cout << " V2's Dimension: " << V2.getDimension() << endl;

	cout << "------------------setDimension(4)------------------" << endl;

	V1.setDimension(4);
	cout << " V1: " << V1;

	V2.setDimension(4);
	cout << " V2: " << V2;

	cout << "------------------(+,-)------------------" << endl;

	Vector V3 = V1 + V2;
	Vector V4 = V2 - V1;

	cout << " V3 = V1 + V2\n"
		 << " V4 = V2 - V1\n";
	cout << " V3: " << V3;
	cout << " V4: " << V4;

	cout << "------------------(+=,-=)------------------" << endl;

	V3 -= V1;
	V4 += V2;
	cout << " V3 -= V1\n"
		 << " V4 += V2\n";
	cout << " V3: " << V3;
	cout << " V4: " << V4;

	cout << "------------------(*)------------------" << endl;

	V3 = V3 * 5;
	V4 = 5 * V4;

	cout << " V3 = V3 * 5\n"
		 << " V4 = 5 * V4\n";
	cout << " V3: " << V3;
	cout << " V4: " << V4;

	cout << "------------------(-,*=)------------------" << endl;

	V3 = -V3;
	V4 *= -1;

	cout << " V3 = -V3\n"
		 << " V4 *= -1\n";
	cout << " V3: " << V3;
	cout << " V4: " << V4;

	cout << "------------------(==,!=)------------------" << endl;

	cout << " V1 != V2 : ";
	V1 != V2 ? cout << "True\n" : cout << "False\n";
	cout << " V3 == V4 : ";
	V3 == V4 ? cout << "True\n" : cout << "False\n";

	cout << "------------------([])------------------" << endl;

	V1[0] = V1[1] = V1[2] = V1[3] = 2;
	cout << " V1[0] = V1[1] = V1[2] = V1[3] = 2\n";
	cout << " V1: " << V1;

	cout << "------------------length()------------------" << endl;

	cout << " V1's length : " << V1.length() << endl;
	cout << " V2's length : " << V2.length() << endl;

	cout << "\n---------------------------------------------" << endl;
}
