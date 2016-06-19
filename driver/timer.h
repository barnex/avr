#ifndef _TIMER_H_
#define _TIMER_H_

#define TIMER_PRESCALE_0    ((0 << CS12) | (0 << CS11) | (0 << CS10))
#define TIMER_PRESCALE_1    ((0 << CS12) | (0 << CS11) | (1 << CS10))
#define TIMER_PRESCALE_8    ((0 << CS12) | (1 << CS11) | (0 << CS10))
#define TIMER_PRESCALE_64   ((0 << CS12) | (1 << CS11) | (1 << CS10))
#define TIMER_PRESCALE_256  ((1 << CS12) | (0 << CS11) | (0 << CS10))
#define TIMER_PRESCALE_1024 ((1 << CS12) | (0 << CS11) | (1 << CS10))
#define TIMER_EXT_FALL      ((1 << CS12) | (1 << CS11) | (0 << CS10))
#define TIMER_EXT_RISE      ((1 << CS12) | (1 << CS11) | (1 << CS10))


void timer_init(uint8_t prescale_mask, uint16_t ticks, void (*f)() );

#endif
