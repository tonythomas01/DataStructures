template <class Type>
Node <Type>::Node() {
  data=0;
  left= NULL;
  right = NULL;
}

template <class Type>
Node <Type>::Node(Type d) {
  data = d;
  left= NULL;
  right = NULL;
}

template <class Type>
Type Node<Type>::get_data() {
  return data;
}
