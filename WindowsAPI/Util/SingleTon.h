#pragma once

template <typename T>
class SingleTon {
protected:
	static T* instance;

	SingleTon() {}
	virtual ~SingleTon() {
		ReleaseInstance();
	}

public:
	static T* GetInstance() {
		if (instance == nullptr) {
			instance = new T;
		}
		return instance;
	}

private:
	static void ReleaseInstance() {
		if (instance != nullptr) {
			delete instance;
		}
		instance = nullptr;
	}
};

//ΩÃ±€≈Ê ¿ŒΩ∫≈œΩ∫ º±æ
template<typename T>
T* SingleTon<T>::instance = nullptr;