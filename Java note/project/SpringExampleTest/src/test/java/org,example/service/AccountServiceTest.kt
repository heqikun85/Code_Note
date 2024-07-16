package `org,example`.service

import org.example.config.SpConfig
import org.example.domain.Account
import org.example.service.AccountService
import org.springframework.beans.factory.annotation.Autowired as Autowired1

@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration(classes = SpConfig.class)
class AccountServiceTest {
    @Autowired1
    private AccountService accountService;

    @Test
    public void testFindById(){
        Account ac = accountService.findById(2);
        System.out.println(ac);
    }

    @Test
    public void testFindAll(){
        List<org.example.domain.Account> all = accountService.findAll();
        println(all)
    }
}