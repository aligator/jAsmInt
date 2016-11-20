#ifndef RAWCOMMAND_H_
#define RAWCOMMAND_H_

class RawCommand {
public:
	RawCommand(uint64_t *raw);
	virtual ~RawCommand();
	byte getCmd();
	byte getInfo();
	uint32_t getBigData();
	uint16_t getData(bool left);

private:
	byte cmd;
	byte info;
	uint32_t data;

	void extractCmd(uint64_t *raw);
	void extractInfo(uint64_t *raw);
	void extractData(uint64_t *raw);
};

#endif /* RAWCOMMAND_H_ */
