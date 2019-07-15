require 'test_helper'

class ComoFuncionaControllerTest < ActionDispatch::IntegrationTest
  test "should get index" do
    get como_funciona_index_url
    assert_response :success
  end

end
