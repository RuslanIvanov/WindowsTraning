#pragma once
#include <iterator>

template<typename ValueType>
class OwnIterator : public std::iterator<std::input_iterator_tag, ValueType>
{
    friend class OwnContainer;
private:
    OwnIterator(ValueType* p);
public:
    OwnIterator(const OwnIterator& it);

    bool operator!=(OwnIterator const& other) const;
    bool operator==(OwnIterator const& other) const; //need for BOOST_FOREACH
    typename OwnIterator::reference operator*() const;
    OwnIterator& operator++();
    operator OwnIterator* () const { return p; }
private:
    ValueType* p;
};

template<typename ValueType>
OwnIterator<ValueType>::OwnIterator(ValueType* p) :
    p(p)
{

}

template<typename ValueType>
OwnIterator<ValueType>::OwnIterator(const OwnIterator& it) :
    p(it.p)
{

}

template<typename ValueType>
bool OwnIterator<ValueType>::operator!=(OwnIterator const& other) const
{
    return p != other.p;
}

template<typename ValueType>
bool OwnIterator<ValueType>::operator==(OwnIterator const& other) const
{
    return p == other.p;
}

template<typename ValueType>
typename OwnIterator<ValueType>::reference OwnIterator<ValueType>::operator*() const
{
    return *p;
}

template<typename ValueType>
OwnIterator<ValueType>& OwnIterator<ValueType>::operator++()
{
    ++p;
    return *this;
}

