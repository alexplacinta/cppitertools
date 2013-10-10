#ifndef WRAP_ITER_HPP__
#define WRAP_ITER_HPP__

#include <iterator>

namespace iter {
    template <typename Iterator>
    class wrap_iter {
        private:
            Iterator iter;
            typename std::iterator_traits<Iterator>::difference_type step;

        public:
            //using difference_type = typename std::iterator_traits<Iterator>::difference_type;
            wrap_iter(const Iterator & iter,
                    typename std::iterator_traits<Iterator>::difference_type step) : 
                iter(iter),
                step(step)
            { }

            wrap_iter & operator++() {
                iter += step;
                return *this;
            }

            bool operator!=(const wrap_iter & rhs) const {
                return this->iter != rhs.iter;
            }

            auto operator*() const -> decltype(*iter)
            {
                return *iter;
            }
    };

    template <typename Iterator>
    wrap_iter<Iterator> make_wrap_iter(const Iterator & iter,
            typename std::iterator_traits<Iterator>::difference_type step) {
        return wrap_iter<Iterator>(iter,step);
    }
    
}
template <typename Iterator>
    struct std::iterator_traits<iter::wrap_iter<Iterator>> {
        using difference_type = typename std::iterator_traits<Iterator>::difference_type;
        //should add the rest later for a more usable class
    };
#endif //WRAP_ITER_HPP__
