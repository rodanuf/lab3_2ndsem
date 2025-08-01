#include "../monad_header/monad_adapter.hpp"

template <monad_container container, typename result_type = container::value_type>
monad_adapter<container, result_type>::monad_adapter() {}

template <monad_container container, typename result_type = container::value_type>
monad_adapter<container, result_type>::monad_adapter(const container &other) : cont(other) {}

template <typename container, typename result_type = container::value_type>
monad_adapter<container, result_type>::monad_adapter(container &&other) : cont(std::forward(other)) {}

template <monad_container container, typename result_type = container::value_type>
monad_adapter<container, result_type>::monad_adapter(const monad_adapter &other) : cont(other.cont) {}

template <monad_container container, typename result_type = container::value_type>
monad_adapter<container, result_type>::monad_adapter(monad_adapter &&other) : cont(std::forward(other.cont)) {}

template <monad_container container, typename result_type = container::value_type>
monad_adapter<container, result_type>::~monad_adapter() {}

template <monad_adapter container, typename result_type = container::value_type>
monad_adapter<container, result_type> &monad_adapter<container, result_type>::operator=(const container &other)
{
    cont = other;
    return *this;
}

template <monad_adapter container, typename result_type = container::value_type>
monad_adapter<container, result_type> &monad_adapter<container, result_type>::operator=(container &&other)
{
    cont = std::forward(other);
    return *this;
}

template <monad_adapter container, typename result_type = container::value_type>
monad_adapter<container, result_type> &monad_adapter<container, result_type>::operator=(const monad_adapter &other)
{
    cont = other.cont;
    return *this;
}

template <monad_adapter container, typename result_type = container::value_type>
monad_adapter<container, result_type> &monad_adapter<container, result_type>::operator=(monad_adapter &&other)
{
    cont = std::forward(other.cont);
    return *this;
}

template <monad_adapter container, typename result_type = container::value_type>
template <map_function<result_type> func>
auto monad_adapter<container, result_type>::map()
{
    container result;
    for (auto it = cont.begin(); it != cont.end(); ++it)
    {
        result.
    }
}
