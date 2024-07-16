package `org,example`.service

import org.example.config.SpConfig
import org.example.service.AccountService
import org.springframework.beans.factory.annotation.Autowired

@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration(classes = SpConfig.class)
public class AccountServiceTest {
    @Autowired
    private AccountService accountService;

    @Test
    public void testFindById(){
        Account ac = accountService.findById(2);
        System.out.println(ac);
    }

    @Test
    public void testFindAll(){
        List<Account> all = accountService.findAll();
        println(all)
    }
}