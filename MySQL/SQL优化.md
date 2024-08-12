[返回目录](./1.MySQL进阶.md)

# SQL优化

### 插入优化

1. insert 优化：批量插入
`insert into tb_text values (1,'tom'),(2,'cat'),...`

2. 手动提交事务：在多个命令完成后，执行commit
3. 主键顺序插入
4. 大量数据插入可以用load指令插入
```sql
# 客户端连接服务端时，加上参数 --local-infile
mysql --local-infile -u root -p
-- 然后设置全局local-infile为0
set global local_infile = 1;
# 执行load指令将准备好的数据，加载到表结构中。
load data local infile '/root/sql1.log' into table 'tb_test' fields terminated by ',' lines terminated by '\n';

```
