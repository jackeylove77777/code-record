using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Xunit.Sdk;

namespace FP_CSHARP
{
    public static class Chapter01
    {
        //问题1
        public static Func<T, bool> Negative<T>(this Func<T, bool> f) => t => !f(t);

        //问题2
        public static List<int> QuickSort(this List<int> lists)
        {
            if (lists.Count == 0) return new List<int> { };

            var prev = lists[0];
            var rest = lists.Skip(1);

            var small = rest.Where(x => x <= prev);
            var big = rest.Where(x => x > prev);

            return small.ToList().QuickSort()
                        .Append(prev)
                        .Concat(big.ToList().QuickSort())
                        .ToList();
        }

        //问题3
        public static List<T> QuickSort<T>(this List<T> lists, Comparison<T> comparison)
        {
            if (lists.Count == 0) return new List<T> { };

            var prev = lists[0];
            var rest = lists.Skip(1);

            var small = rest.Where(x => comparison(x, prev) <= 0);
            var big = rest.Where(x => comparison(x, prev) > 0);

            return small.ToList().QuickSort(comparison)
                        .Append(prev)
                        .Concat(big.ToList().QuickSort(comparison))
                        .ToList();
        }

        //问题4
        public static R Using<TDisp, R>(Func<TDisp> createDisposable, Func<TDisp, R> f) where TDisp : IDisposable
        {
            using var disposable = createDisposable();
            return f(disposable);
        }

    }
}
