#include <iostream>
#include <fstream>
#include <string>
#include <Eigen/Core>
#include <Eigen/Dense>

#include "ReadCodebook.h"
#include "vl/fisher.h"
#include "vl/generic.h"

/*void split(vector<vector<float> >* data_buf, int hog_dim, int hof_dim, int mbx_dim, int mby_dim, 
		Eigen::MatrixXf* hog_m, Eigen::MatrixXf* hof_m, Eigen::MatrixXf* mbx_m, Eigen::MatrixXf* mby_m) {
	int num_data = data_buf->size();
	
}*/
void codebook::OrthoProjection(float* data, const int num_samples) {
	Eigen::MatrixXf m = Eigen::Map<Eigen::MatrixXf>(data, dimension_, num_samples);
	Eigen::VectorXf center = Eigen::Map<Eigen::VectorXf>(proj_centers_, dimension_);
	Eigen::MatrixXf proj = Eigen::Map<Eigen::MatrixXf>(projections_, dimension_, dimension_);
	for (int i = 0; i < num_samples; ++i) {
		m.col(i) -= center;	
	}
	m = proj * m;

	float* result = new float[dimension_ * centers_ * 2];

	vl_fisher_encode(result, VL_TYPE_FLOAT, means_, dimension_, centers_,
		covariances_, prior_, m.data(), num_samples, 3);

	delete result;
/*

	float *result = new float[4];
	float *means = new float[2];
	float *covariances = new float[2];
	float *priors = new float[2];
	float *data = new float [4];
	int numData = 2;
	int dimension = 2;
	int numClusters = 2;
	vl_type dataType = VL_TYPE_FLOAT;
	
	vl_fisher_encode (result, dataType,
                               means, dimension, numClusters,
                               covariances,
                               priors,
                               data, numData,
                               3) ;
*/
}

codebook::codebook(std::string name, float* data, int dimension, int centers) {
	name_ = name;
	dimension_ = dimension;
	centers_ = centers;
	int curr_idx = 0;
	means_ = data;
	curr_idx += dimension_ * centers_;
	covariances_ = data + curr_idx;
	curr_idx += dimension_ * centers_;
	prior_ = data + curr_idx;
	curr_idx += centers_;
	proj_centers_ = data + curr_idx;
	curr_idx += dimension_;
	projections_ = data + curr_idx;
}
/*
int main() {
	std::ifstream inputFile;
	inputFile.open("/home/rhou/Downloads/improved_trajectory_release/codebook.bin", std::ios::in | std::ios::binary);
	if (!inputFile.is_open()) {
		std::cout<< "No such file!" << std::endl;
		return 0;
	}
	float *data = new float[243484];
	inputFile.read((char*)data, sizeof(float) * 243484);
	codebook hof("hof", data, 108, 256);
	float* data2 = new float[648];
	for (int i = 0; i < 648; ++i) {
		data2[i] = i;
	}
	hof.OrthoProjection(data2, 108, 6);
	delete data;
	inputFile.close();
	return 0;
}*/
