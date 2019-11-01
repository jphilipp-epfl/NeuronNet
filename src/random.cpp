#include "random.h"

RandomNumbers::RandomNumbers(unsigned long int s)
{
	if (s == 0)
	{
		std::random_device rd;
		seed = rd();
	}
	rng = std::mt19937(seed);
};


void RandomNumbers::uniform_double(std::vector<double>& vec, double lower, double upper)
{
	std::uniform_real_distribution<double> uniform_distrib(lower,upper);
	for (size_t i(0);i<vec.size();++i)
	{
		vec[i] = uniform_distrib(rng);
	}
};

double RandomNumbers::uniform_double(double lower, double upper)
{
	std::uniform_real_distribution<double> uniform_distrib(lower,upper);
	return uniform_distrib(rng);
};

void RandomNumbers::normal(std::vector<double>& vec, double mean, double sd)
{
	std::normal_distribution<double> normal_distrib(mean,sd);
	for (size_t i(0);i<vec.size();++i)
	{
		vec[i] = normal_distrib(rng);
	}
};

double RandomNumbers::normal(double mean,double sd)
{
	std::normal_distribution<double> normal_distrib(mean,sd);
	return normal_distrib(rng);
};

void RandomNumbers::poisson(std::vector<int>& vec, double mean)
{
	std::poisson_distribution<int> poisson_distrib(mean);
	for (size_t i(0);i<vec.size();++i)
	{
		vec[i] = poisson_distrib(rng);
	}
};

int RandomNumbers::poisson(double mean)
{
	std::poisson_distribution<int> poisson_distrib(mean);
	return poisson_distrib(rng);
};
