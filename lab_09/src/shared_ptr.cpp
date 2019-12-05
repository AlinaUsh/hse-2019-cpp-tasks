#include "shared_ptr.hpp"
#include <algorithm>

shared_ptr::shared_ptr(Matrix* obj) {
    storage_ = nullptr;
    if (obj != nullptr)
        storage_ = new Storage(obj);
}

shared_ptr::shared_ptr(const shared_ptr& other) {
    storage_ = nullptr;
    if (other.storage_ != nullptr) {
        storage_ = other.storage_;
        storage_->incr();
    }
}

shared_ptr& shared_ptr::operator=(shared_ptr other) {
    std::swap(storage_, other.storage_);
    return *this;
}

shared_ptr::~shared_ptr() {
    if (storage_ != nullptr) {
	storage_->decr();
	if (storage_->getCounter() == 0)
	    delete storage_;
    }
} 

Matrix* shared_ptr::ptr() const {
    if (storage_ != nullptr)
        return storage_->getObject();   
    return nullptr;
}

bool shared_ptr::isNull() const {
    return storage_ == nullptr;
}

void shared_ptr::reset(Matrix* obj) {
    if (storage_ != nullptr) {
	storage_->decr();
	if (storage_->getCounter() == 0) {
	    delete storage_;
	}
    }
    if (obj != nullptr)
        storage_ = new Storage(obj);
    else
	storage_ = nullptr;
}

Matrix* shared_ptr::operator->() const {
    if (storage_ == nullptr)
	return nullptr;
    return storage_->getObject();
}

Matrix& shared_ptr::operator*() const {
    return *storage_->getObject();
}

shared_ptr::Storage::Storage(Matrix* mtx) {
    data_ = mtx;
    ref_count_ = 1;
}

shared_ptr::Storage::~Storage() {
    delete data_;
}

void shared_ptr::Storage::incr() {
    ref_count_++;
    return;
}

void shared_ptr::Storage::decr() {
    ref_count_--;
    return;
}

int shared_ptr::Storage::getCounter() const {
    return ref_count_;
}

Matrix* shared_ptr::Storage::getObject() const {
    return data_;
}
