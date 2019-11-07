#pragma once

#include <algorithm> // std::max
#include <cstddef>   // std::size_t
#include <iomanip>   // std::setw
#include <ostream>   // std::ostream
#include <sstream>   // std::ostringstream


namespace utils {
// Compute the maximum value of an image
    template <typename Img>
    typename Img::value_type max(const Img& img)
    {
        const auto d    = img.domain();
        auto       p_it = typename Img::p_iterator_type(d);

        p_it.start();
        auto max = img(p_it.value());
        for (p_it.next(); p_it.is_valid(); p_it.next()) {
            const auto tmp = img(p_it.value());
            if (max < tmp) {
                max = tmp;
            }
        }

        return max;
    }

// Compute the minimum value of an image
    template <typename Img>
    typename Img::value_type min(const Img& img)
    {
        const auto d    = img.domain();
        auto       p_it = typename Img::p_iterator_type(d);

        p_it.start();
        auto min = img(p_it.value());
        for (p_it.next(); p_it.is_valid(); p_it.next()) {
            const auto tmp = img(p_it.value());
            if (min > tmp) {
                min = tmp;
            }
        }

        return min;
    }

// Compute the width as string of a value
    template <typename T>
    std::size_t string_width(T val)
    {
        std::ostringstream oss;
        oss << val;
        return oss.str().size();
    }

    template <typename Img>
    std::size_t string_max_width(const Img& img)
    {
        return std::max(string_width(max(img)), string_width(min(img)));
    }

    template <typename T, typename U>
    bool image_equal_to(const T& lhs, const U& rhs)
    {
        const auto d_lhs = lhs.domain();

        if (d_lhs != rhs.domain()) {
            return false;
        }

        auto it = typename T::p_iterator_type(d_lhs);
        for (it.start(); it.is_valid(); it.next()) {
            if (lhs(it) != rhs(it)) {
                return false;
            }
        }

        return true;
    }

    template <typename T>
    std::ostream& print_image(std::ostream& os, const T& rhs)
    {
        const auto d     = rhs.domain();
        const auto width = string_max_width(rhs);
        for (int i = 0, rows = d.rows(); i < rows; ++i) {
            os << "|";
            const auto cols = d.cols() - 1;
            for (int j = 0; j < cols; ++j) {
                const auto p = typename T::point_type{i, j};
                if (!d.has(p)) {
                    // numeral width + 2 spaces for ',' and ' ' which are omitted
                    os << std::setw(width + 2) << " ";
                }
                else {
                    os << std::setw(width) << rhs(p) << ", ";
                }
            }
            const auto p = typename T::point_type{i, cols};
            if (!d.has(p)) {
                os << std::setw(width) << " "
                   << "|\n";
            }
            else {
                os << std::setw(width) << rhs({i, cols}) << "|\n";
            }
        }

        return os;
    }

} // namespace utils