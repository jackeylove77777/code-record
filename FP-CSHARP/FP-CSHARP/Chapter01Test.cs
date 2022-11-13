using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
#nullable disable
namespace FP_CSHARP
{
    public class Chapter01Test
    {
        public record struct Student(string name, int age);

        [Fact]
        public void NegativeShould()
        {
            Func<int, bool> func = (x) => x >= 0;//大于0返回true

            var negative = func.Negative();
            Assert.True(negative(-1));
            Assert.False(negative(1));
        }

        //第一个快排要做的
        [Fact]
        public void QuickSortShould()
        {
            var list = new List<int> { 2, 1, 6, 8, 2, 0, 9 };
            var sorted = list.OrderBy(x => x);//List自带的排序函数,返回新的List

            var quicksorted = list.QuickSort();
            Assert.Equal(sorted, quicksorted);
            //是否返回了新的List
            Assert.NotSame(sorted, list);
        }

        //第二个泛型快排
        [Fact]
        public static void GeneralizeQuickSortShould()
        {
            var list = new List<short> { 2, 1, 6, 8, 2, 0, 9 };
            var persons = new List<Student>
            {
                new Student("jiejie",18),
                new Student("meiko",19),
                new Student("rookie",11),
                new Student("uzi",22),
                new Student("369",3),
                new Student("scout",55),
                new Student("jackeylove",58),
                new Student("deft",14),
            };
            var sorted = list.OrderBy(x => x);
            var sortedPerson = persons.OrderBy(x => x.age);

            var quicksorted = list.QuickSort((a, b) => a - b);
            var PersonQuicksorted = persons.QuickSort((a, b) => a.age - b.age);

            Assert.Equal(sorted, quicksorted);
            Assert.NotSame(quicksorted, list);

            Assert.Equal(sortedPerson, PersonQuicksorted);
            Assert.NotSame(persons, PersonQuicksorted);
        }
    }
}
