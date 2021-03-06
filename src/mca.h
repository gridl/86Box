extern void mca_init(int nr_cards);
extern void mca_add(uint8_t (*read)(int addr, void *priv), void (*write)(int addr, uint8_t val, void *priv), void *priv);
extern void mca_set_index(int index);
extern uint8_t mca_read(uint16_t port);
extern void mca_write(uint16_t port, uint8_t val);
