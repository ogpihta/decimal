#include "../../s21_decimal.h"
// Побитовый сдвиг влево
int left_shift(long_decimal *value) {
  // Выбор позиции нулевого бита из *value
  int answer = get_bit(*value, 0);
  // Цикл для смещения элмемента каждого бита на 1 позицию влево
  for (int i = 5; i > 0; i--) {
    value->bits[i] <<= 1;
    // Проверка для границ битов, если в предыдущем bit[i-1] старший бит равен
    // 1, то добавляем 1 к bit[i]
    value->bits[i] += (value->bits[i - 1] >= (1u << 31));
  }
  // Двигаем последний бит без проверок
  value->bits[0] <<= 1;
  // Возврат значение answ с положением нулевого бита 0 элемента до сдвига
  return answer;
}
