"""Решение транспортной задачи методом северо-западного угла
    и методом минимального элемента."""

import copy

def balance_condition(reserves, needs):
    """Проверяем условие баланса для запасов и запросов."""
    return bool(sum(reserves) == sum(needs))

def method_north_west_corner(reserves, needs):
    """Метод северо-западного угла. В качестве параметров - запасы, запросы"""
    route = [[int(0) for j in range(len(needs))] for i in range(len(reserves))]
    if balance_condition(reserves, needs):
        i, j = 0, 0
        for m in range(len(reserves) + len(needs) - 1):
            if reserves[i] - needs[j] >= 0:
                route[i][j] = needs[j]
                reserves[i] -= needs[j]
                j += 1
            elif reserves[i] > 0:
                needs[j] -= reserves[i]
                route[i][j] = reserves[i]
                i += 1
            if j == len(needs):
                break
    return route

def method_min_element(reserves, needs, tariffs):
    """Метод минимального элемента. В качестве параметров - запасы, запросы, тарифы"""
    route = [[int(0) for j in range(len(needs))] for i in range(len(reserves))]
    if balance_condition(reserves, needs):
        for m in range(len(reserves) + len(needs) - 1):
            min_ = min(map(min, tariffs))
            # Находим минимальную стоимость
            for i, j in enumerate(tariffs):
                try:
                    k = i
                    l = j.index(min_)
                    break
                except ValueError:
                    pass
            if reserves[k] > needs[l]:
                route[k][l] = needs[l]
                reserves[k] -= needs[l]
                # Если потребность выполнена, то исключаем соот-й столбец
                for x in range(len(reserves)):
                    tariffs[x][l] = float("inf")
            elif reserves[k] >= 0:
                route[k][l] = reserves[k]
                needs[l] -= reserves[k]
                # Если запасы исчерпаны, то исключаем соот-ю строку
                reserves[k] = 0
                for x in range(len(needs)):
                    tariffs[k][x] = float("inf")
    return route

def print_plan(route):
    """Печать допустимого плана. В качестве параметров - таблица распределения грузов."""
    print("Допустимый план:")
    for i in range(len(route)):
        for j in range(len(route[i])):
            if route[i][j] > 0:
                print("Из пункта A" + str(i + 1) + " в пункт В" + str(j + 1) + " ->", route[i][j])

def cost(tariffs, route):
    """Расчёт стоимости перевозки грузов.
        В качестве параметров - тарифы и таблица распределения грузов."""
    sum = 0
    for i, k in zip(route, tariffs):
        for j, l in zip(i, k):
            if j > 0 and l > 0:
                sum += j * l
    return sum


def main():
    """Основная функция"""
    with open("input.txt") as file:
        # Запасы
        reserves_ = [int(i) for i in file.readline().split()]
        # Потребности
        needs_ = [int(i) for i in file.readline().split()]
        # Тарифы
        tariffs_ = [[int(j) for j in file.readline().split()] for i in range(len(reserves_))]
    tariffs_copy = copy.deepcopy(tariffs_)
    number_variant = int(
        input("Выберите метод расчёта: 1 - метод северо-западного угла, 2 - метод минимального угла: "))
    if number_variant == 1:
        route = method_north_west_corner(reserves_, needs_)
    else:
        route = method_min_element(reserves_, needs_, tariffs_copy)
    print_plan(route)
    print("Стоимость перевозок составит:", cost(tariffs_, route))

if __name__ == '__main__':
    main()
