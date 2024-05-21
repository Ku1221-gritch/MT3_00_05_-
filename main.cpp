#include <Novice.h>
#define _USE_MATH_DEFINES
#include<cmath>

const char kWindowTitle[] = "学籍番号";

struct Vector3 {
	float x, y, z;
};

struct Matrix4x4 {
	float m[4][4];
};

//1.平行移動行列
Matrix4x4 MakeTranslateMatrix(const Vector3& translate)
{
	Matrix4x4 Answer;
	Answer.m[0][0] = 1;
	Answer.m[0][1] = 0;
	Answer.m[0][2] = 0;
	Answer.m[0][3] = 0;
	Answer.m[1][0] = 0;
	Answer.m[1][1] = 1;
	Answer.m[1][2] = 0;
	Answer.m[1][3] = 0;
	Answer.m[2][0] = 0;
	Answer.m[2][1] = 0;
	Answer.m[2][2] = 1;
	Answer.m[2][3] = 0;
	Answer.m[3][0] = translate.x;
	Answer.m[3][1] = translate.y;
	Answer.m[3][2] = translate.z;
	Answer.m[3][3] = 1;
	return Answer;
}

//2.拡大縮小行列
Matrix4x4 MakeScaleMatrix(const Vector3& scale)
{
	Matrix4x4 Answer;
	Answer.m[0][0] = scale.x;
	Answer.m[0][1] = 0;
	Answer.m[0][2] = 0;
	Answer.m[0][3] = 0;
	Answer.m[1][0] = 0;
	Answer.m[1][1] = scale.y;
	Answer.m[1][2] = 0;
	Answer.m[1][3] = 0;
	Answer.m[2][0] = 0;
	Answer.m[2][1] = 0;
	Answer.m[2][2] = scale.z;
	Answer.m[2][3] = 0;
	Answer.m[3][0] = 0;
	Answer.m[3][1] = 0;
	Answer.m[3][2] = 0;
	Answer.m[3][3] = 1;
	return Answer;
}


//1.X軸回転行列
Matrix4x4 MakeRotateXMatrix(float radian)
{
	Matrix4x4 Answer;
	Answer.m[0][0] = 1;
	Answer.m[0][1] = 0;
	Answer.m[0][2] = 0;
	Answer.m[0][3] = 0;
	Answer.m[1][0] = 0;
	Answer.m[1][1] = std::cos(radian);
	Answer.m[1][2] = std::sin(radian);
	Answer.m[1][3] = 0;
	Answer.m[2][0] = 0;
	Answer.m[2][1] = -std::sin(radian);
	Answer.m[2][2] = std::cos(radian);
	Answer.m[2][3] = 0;
	Answer.m[3][0] = 0;
	Answer.m[3][1] = 0;
	Answer.m[3][2] = 0;
	Answer.m[3][3] = 1;
	return Answer;
}

//2.Y軸回転行列
Matrix4x4 MakeRotateYMatrix(float radian)
{
	Matrix4x4 Answer;
	Answer.m[0][0] = std::cos(radian);
	Answer.m[0][1] = 0;
	Answer.m[0][2] = -std::sin(radian);
	Answer.m[0][3] = 0;
	Answer.m[1][0] = 0;
	Answer.m[1][1] = 1;
	Answer.m[1][2] = 0;
	Answer.m[1][3] = 0;
	Answer.m[2][0] = std::sin(radian);
	Answer.m[2][1] = 0;
	Answer.m[2][2] = std::cos(radian);
	Answer.m[2][3] = 0;
	Answer.m[3][0] = 0;
	Answer.m[3][1] = 0;
	Answer.m[3][2] = 0;
	Answer.m[3][3] = 1;
	return Answer;
}

//3.Z軸回転行列
Matrix4x4 MakeRotateZMatrix(float radian)
{
	Matrix4x4 Answer;
	Answer.m[0][0] = std::cos(radian);
	Answer.m[0][1] = std::sin(radian);
	Answer.m[0][2] = 0;
	Answer.m[0][3] = 0;
	Answer.m[1][0] = -std::sin(radian);
	Answer.m[1][1] = std::cos(radian);
	Answer.m[1][2] = 0;
	Answer.m[1][3] = 0;
	Answer.m[2][0] = 0;
	Answer.m[2][1] = 0;
	Answer.m[2][2] = 1;
	Answer.m[2][3] = 0;
	Answer.m[3][0] = 0;
	Answer.m[3][1] = 0;
	Answer.m[3][2] = 0;
	Answer.m[3][3] = 1;
	return Answer;
}

//3.行列の積
Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2)
{
	Matrix4x4 Answer;
	Answer.m[0][0] = m1.m[0][0] * m2.m[0][0]
		+ m1.m[0][1] * m2.m[1][0]
		+ m1.m[0][2] * m2.m[2][0]
		+ m1.m[0][3] * m2.m[3][0];
	Answer.m[0][1] = m1.m[0][0] * m2.m[0][1]
		+ m1.m[0][1] * m2.m[1][1]
		+ m1.m[0][2] * m2.m[2][1]
		+ m1.m[0][3] * m2.m[3][1];
	Answer.m[0][2] = m1.m[0][0] * m2.m[0][2]
		+ m1.m[0][1] * m2.m[1][2]
		+ m1.m[0][2] * m2.m[2][2]
		+ m1.m[0][3] * m2.m[3][2];
	Answer.m[0][3] = m1.m[0][0] * m2.m[0][3]
		+ m1.m[0][1] * m2.m[1][3]
		+ m1.m[0][2] * m2.m[2][3]
		+ m1.m[0][3] * m2.m[3][3];
	Answer.m[1][0] = m1.m[1][0] * m2.m[0][0]
		+ m1.m[1][1] * m2.m[1][0]
		+ m1.m[1][2] * m2.m[2][0]
		+ m1.m[1][3] * m2.m[3][0];
	Answer.m[1][1] = m1.m[1][0] * m2.m[0][1]
		+ m1.m[1][1] * m2.m[1][1]
		+ m1.m[1][2] * m2.m[2][1]
		+ m1.m[1][3] * m2.m[3][1];
	Answer.m[1][2] = m1.m[1][0] * m2.m[0][2]
		+ m1.m[1][1] * m2.m[1][2]
		+ m1.m[1][2] * m2.m[2][2]
		+ m1.m[1][3] * m2.m[3][2];
	Answer.m[1][3] = m1.m[1][0] * m2.m[0][3]
		+ m1.m[1][1] * m2.m[1][3]
		+ m1.m[1][2] * m2.m[2][3]
		+ m1.m[1][3] * m2.m[3][3];
	Answer.m[2][0] = m1.m[2][0] * m2.m[0][0]
		+ m1.m[2][1] * m2.m[1][0]
		+ m1.m[2][2] * m2.m[2][0]
		+ m1.m[2][3] * m2.m[3][0];
	Answer.m[2][1] = m1.m[2][0] * m2.m[0][1]
		+ m1.m[2][1] * m2.m[1][1]
		+ m1.m[2][2] * m2.m[2][1]
		+ m1.m[2][3] * m2.m[3][1];
	Answer.m[2][2] = m1.m[2][0] * m2.m[0][2]
		+ m1.m[2][1] * m2.m[1][2]
		+ m1.m[2][2] * m2.m[2][2]
		+ m1.m[2][3] * m2.m[3][2];
	Answer.m[2][3] = m1.m[2][0] * m2.m[0][3]
		+ m1.m[2][1] * m2.m[1][3]
		+ m1.m[2][2] * m2.m[2][3]
		+ m1.m[2][3] * m2.m[3][3];
	Answer.m[3][0] = m1.m[3][0] * m2.m[0][0]
		+ m1.m[3][1] * m2.m[1][0]
		+ m1.m[3][2] * m2.m[2][0]
		+ m1.m[3][3] * m2.m[3][0];
	Answer.m[3][1] = m1.m[3][0] * m2.m[0][1]
		+ m1.m[3][1] * m2.m[1][1]
		+ m1.m[3][2] * m2.m[2][1]
		+ m1.m[3][3] * m2.m[3][1];
	Answer.m[3][2] = m1.m[3][0] * m2.m[0][2]
		+ m1.m[3][1] * m2.m[1][2]
		+ m1.m[3][2] * m2.m[2][2]
		+ m1.m[3][3] * m2.m[3][2];
	Answer.m[3][3] = m1.m[3][0] * m2.m[0][3]
		+ m1.m[3][1] * m2.m[1][3]
		+ m1.m[3][2] * m2.m[2][3]
		+ m1.m[3][3] * m2.m[3][3];
	return Answer;
}

Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate) {
	Matrix4x4 result = Multiply(
		Multiply(MakeRotateXMatrix(rotate.x), MakeRotateYMatrix(rotate.y)),
		MakeRotateZMatrix(rotate.z));
	result.m[0][0] *= scale.x;
	result.m[0][1] *= scale.x;
	result.m[0][2] *= scale.x;
	result.m[1][0] *= scale.y;
	result.m[1][1] *= scale.y;
	result.m[1][2] *= scale.y;
	result.m[2][0] *= scale.z;
	result.m[2][1] *= scale.z;
	result.m[2][2] *= scale.z;
	result.m[3][0] = translate.x;
	result.m[3][1] = translate.y;
	result.m[3][2] = translate.z;
	return result;
}

Vector3 scale{ 1.2f,0.79f,-2.1f };
Matrix4x4 scaleMatrix = MakeScaleMatrix(scale);
Vector3 rotate{ 0.4f,1.43f,-0.8f };
Matrix4x4 rotateXMatrix = MakeRotateXMatrix(rotate.x);
Matrix4x4 rotateYMatrix = MakeRotateYMatrix(rotate.y);
Matrix4x4 rotateZMatrix = MakeRotateZMatrix(rotate.z);
Matrix4x4 rotateXYZMatrix = Multiply(rotateXMatrix, Multiply(rotateYMatrix, rotateZMatrix));
Vector3 translate{ 2.7f,-4.15f,1.57f };
Matrix4x4 translateMatrix = MakeTranslateMatrix(translate);
Matrix4x4 worldMatrix = MakeAffineMatrix(scale, rotate, translate);

static const int kRowHeight = 20;
static const int kColumnWidth = 60;

void MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix, const char[]) {
	for (int row = 0; row < 4; ++row) {
		for (int column = 0; column < 4; ++column) {
			Novice::ScreenPrintf(x + column * kColumnWidth, y + row * kRowHeight, "%6.02f", matrix.m[row][column]);
		}
	}
}


// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		Novice::ScreenPrintf(0, 0, "worldMatrix");
		MatrixScreenPrintf(0, kRowHeight, worldMatrix, "worldMatrix");

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}

