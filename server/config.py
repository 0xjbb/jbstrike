
class Config:

    def parse(self, config_file_name):
        with open(config_file_name) as fh:
            data = fh.readlines()
        self.config = ""
